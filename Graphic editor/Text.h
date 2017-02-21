#pragma once

#include <SFML/Graphics.hpp>
 
 
class FocusObject
{
public:
    virtual void setFocus () = 0 ;
    virtual void deleteFocus () = 0 ;
    virtual void event ( const sf::Event & ) = 0 ;
} ;
 
 
 
class TextBox : public sf::Drawable , public FocusObject /*, public sf::Transformable */
{
public:
    TextBox ( const sf::Text & text ) : m_text ( text )
    {
        m_newText = m_text.getString() ;
        updateRect() ;
        m_box.setFillColor( sf::Color::Blue ) ;
    }
    virtual void draw ( sf::RenderTarget & render , sf::RenderStates states ) const
    {
        if ( m_textChanged )
        {
            const_cast<TextBox*>(this)->setText ( m_newText ) ;
 
            m_textChanged = false ;
        }
        render.draw ( m_box , states ) ;
        render.draw ( m_text , states ) ;
    }
    virtual void setFocus ()
    {
        m_box.setFillColor( sf::Color::Transparent ) ;
    }
    virtual void deleteFocus ()
    {
        m_box.setFillColor( sf::Color::Black ) ;
    }
    virtual void event ( const sf::Event & event )
    {
        if (event.type == sf::Event::TextEntered)
        {
            //Обработка ввода
            m_textChanged = true ;
            switch ( event.text.unicode )
            {
            case 0xD: //Return
                m_newText += L'\n' ;
                break ;
            case 0x8://Backspace
                if ( !m_newText.isEmpty() )
                    m_newText.erase(m_newText.getSize()-1) ;
                break ;
            default :
                {
                    m_newText += static_cast<wchar_t>(event.text.unicode) ;
                }
            }
        }
    }
    void setText ( const sf::String & str )
    {
        m_text.setString ( str ) ;
        updateRect() ;
    }
private:
    void updateRect ()
    {
        sf::FloatRect rect = m_text.getGlobalBounds() ;
        m_box.setPosition ( rect.left-5 , rect.top-5 ) ;
        m_box.setSize( sf::Vector2f(rect.width+10 , rect.height+10) ) ;
    }
    mutable sf::RectangleShape m_box ;
    mutable sf::Text m_text ;
    mutable sf::String m_newText ;
    mutable bool m_textChanged ;
} ;
 
 
 
class FocusController
{
public:
    FocusController ( FocusObject * obj = 0 ) : m_object (obj)
    {
        if ( m_object != 0 )
        {
            m_object->setFocus () ;
        }
    }
    void setFocusObject ( FocusObject * new_obj )
    {
        if ( m_object == new_obj )
            return ;
        if ( m_object != 0 )
            m_object->deleteFocus() ;
        if ( new_obj != 0 )
            new_obj->setFocus() ;
        m_object = new_obj ;
    }
    FocusObject * getFocusObject ( )
    {
        return m_object ;
    }
 
private:
    FocusObject * m_object ;
} ;
 

