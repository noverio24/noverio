/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Hafizi
 */
public class Pizza {
    private double payment;
    private String pizza;
    private String drink;
     private String toping;

    public double getPayment() {
        return payment;
    }

    public String getPizza() {
        return pizza;
    }

    public void setPayment(double payment) {
        this.payment = payment;
    }

    public void setPizza(String pizza) {
        this.pizza = pizza;
    }
    
     public String getDrink() {
        return drink;
    }
     
      public void setDrink(String drink) {
        this.drink = drink;
    }
   
        public String getTop() {
        return toping;
    }
     
      public void setTop(String top) {
        this.toping= toping;
    }
}
