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
        m_box.setFillColor( sf::Color::White ) ;
		m_text.setFillColor(Color::Black);
    }

	void SetColor (Color color)
	{
		m_text.setFillColor(color);
	
	}	

	String GetText()
	{
		return m_text.getString();

	}

	void SetPosition (Vector2f position)
	{
		m_text.setPosition(position.x, position.y);
		m_box.setPosition(position.x, position.y);
	
	}	
    virtual void draw ( sf::RenderTarget & render , sf::RenderStates states ) const
    {
        if ( m_textChanged )
        {
			 m_box.setFillColor( sf::Color::White ) ;
            const_cast<TextBox*>(this)->setText ( m_newText ) ;
 
            m_textChanged = false ;
        }
        //render.draw ( m_box , states ) ;
        render.draw ( m_text , states ) ;
    }
    virtual void setFocus ()
    {
        m_box.setFillColor( sf::Color::White ) ;
    }
    virtual void deleteFocus ()
    {
        m_box.setFillColor( sf::Color::White ) ;
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
		 m_box.setFillColor( sf::Color::White ) ;
		
        sf::FloatRect rect = m_text.getGlobalBounds() ;
        m_box.setPosition ( rect.left-1, rect.top-5 ) ;
        m_box.setSize( sf::Vector2f(rect.width+27, rect.height+10) ) ;
		if(m_box.getPosition().x + rect.width >=643)  m_newText += L'\n' ;
		
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
 

