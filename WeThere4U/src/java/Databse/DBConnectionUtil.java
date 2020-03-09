/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Databse;

import java.sql.Connection;
import java.sql.DriverManager;

/**
 *
 * @author Yeasin
 */
public class DBConnectionUtil {
    public static Connection openConnection(){
        String driver = "com.mysql.jdbc.Driver";
        String connectionURL = "jdbc:mysql://localhost:3306/wethere4u";
        String username = "root";
        String password = "";
        Connection connection = null;
        try{
            
        Class.forName(driver);
        connection = DriverManager.getConnection(connectionURL, username, password);
        
        }catch(Exception e){
            
            e.printStackTrace();
        
        }
        return connection;
    }
}
