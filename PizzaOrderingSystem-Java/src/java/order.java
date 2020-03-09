/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author user
 */
@WebServlet(urlPatterns = {"/order"})
public class order extends HttpServlet {

    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
       
       
        PrintWriter w = response.getWriter();
        response.setContentType("text/html");
        String pizza = request.getParameter("pizza");   
        String drink = request.getParameter("drink"); 
        
        String toping = request.getParameter("toping");   
        int price1 = 0, price2 = 0, price = 0;
      
       
     
    if(pizza.equals("Beef Pepperoni")){
            price1 = 8; 
        }
        else if(pizza.equals("Island Tuna")){
            price1 = 7;
        }
        else if(pizza.equals("Chicken Supreme")){
            price1 = 9;
        }
        else if(pizza.equals("Super Supreme")){
            price1 = 10;
        }
        
    
    if(drink.equals("Coca Cola")){
            price2 = 3;
        }
        else if(drink.equals("Nestea Lemon Tea")){
            price1 = 2;
        }
        else if(drink.equals("Milo")){
            price2 = 3;
        }
        else if(drink.equals("Mineral Water")){
            price2 = 1;
        }
    
    if(toping.equals("") == false){
        
            price1+=1;
    }
        price = price1 + price2;
      
            HttpSession session = request.getSession();
            session.setAttribute("pizza", pizza);
            session.setAttribute("price1", price1);
            session.setAttribute("price2", price2);
            session.setAttribute("price", price);
            session.setAttribute("drink", drink);
            session.setAttribute("toping", toping);
            response.sendRedirect("Payment1.jsp");
        
     
        
    }

 
}
