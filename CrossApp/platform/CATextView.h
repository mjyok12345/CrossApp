//
//  CATextView.hpp
//  tesss
//
//  Created by 栗元峰 on 15/11/20.
//
//

#ifndef CATextView_h
#define CATextView_h


#include "view/CAImageView.h"
#include "view/CAScale9ImageView.h"

NS_CC_BEGIN




class CC_DLL CATextView;
class CC_DLL CATextViewDelegate
{
public:
    
    virtual ~CATextViewDelegate(){}
    
    virtual bool textViewShouldBeginEditing(CATextView* sender)
    {
        return true;
    }
    
    //If the sender doesn't want to detach from the IME, return true;
    virtual bool textViewShouldEndEditing(CATextView* sender)
    {
        return true;
    }
    
    //
    virtual void textViewShouldReturn(CATextView* sender){}

    //
    virtual void keyBoardHeight(CATextView* sender, int height){}
    
    //Warning!!! Warning!!! Warning!!!  This method is not on the OpenGL thread.
    virtual bool textViewShouldChangeCharacters(CATextView* sender,
                                                 unsigned int location,
                                                 unsigned int lenght,
                                                 const std::string& changedText)
    {
        return true;
    }
};



class CC_DLL CATextView : public CAView
{
public:
    typedef enum
    {
        Left = 0,
        Center,
        Right
    }TextViewAlign;
    
    //return type
    typedef enum
    {
        Default=0,
        Done,
        Send,
        Next
    }ReturnType;
    
public:
    CATextView();
    
    virtual ~CATextView();
    
    virtual void onEnterTransitionDidFinish();
    
    virtual void onExitTransitionDidStart();
    
    virtual bool resignFirstResponder();
    
    virtual bool becomeFirstResponder();
    
    static CATextView* createWithFrame(const DRect& frame);
    
    static CATextView* createWithCenter(const DRect& rect);
    
    
    //delegate
    CC_SYNTHESIZE(CATextViewDelegate*, m_pDelegate, Delegate);
    
    //Text     Text/Color
    CC_PROPERTY_PASS_BY_REF(std::string, m_sText, Text);
    CC_PROPERTY_PASS_BY_REF(CAColor4B, m_sTextColor, TextColor);
    
    //fontSize
    CC_PROPERTY_PASS_BY_REF(int, m_iFontSize, TextFontSize);
    
    //TextViewAlign
    CC_PROPERTY_PASS_BY_REF(TextViewAlign,m_eAlign,TextViewAlign);
    
    //returnType       default:ReturnTypeDefault
    CC_PROPERTY_PASS_BY_REF(ReturnType, m_eReturnType, ReturnType);
    
    //BackgroundImage
    void setBackgroundImage(CAImage* image);
    
private:
    bool init();
    
    const DRect convertRect(const DRect& rect);
    
    void delayShowImage();
    
    void showImage();
    
    void hideTextView();
    
    void showTextView();
    
    void hideNativeTextView();
    
    void showNativeTextView();
    
    virtual void setContentSize(const DSize& contentSize);
    
    void        update(float t);

    virtual bool ccTouchBegan(CATouch *pTouch, CAEvent *pEvent);
    
    virtual void ccTouchMoved(CATouch *pTouch, CAEvent *pEvent);
    
    virtual void ccTouchEnded(CATouch *pTouch, CAEvent *pEvent);
    
    virtual void ccTouchCancelled(CATouch *pTouch, CAEvent *pEvent);
    
protected:
    
    CAScale9ImageView*   m_pBackgroundView;
    
    CAImageView*         m_pShowImageView;
    
    void*                m_pTextView;
    
    DPoint               m_obLastPoint;
};

NS_CC_END

#endif /* CATextView_hpp */