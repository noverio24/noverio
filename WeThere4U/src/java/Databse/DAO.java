package Databse;

import ModelPackage.Admin;
import ModelPackage.Customer;
import ModelPackage.Home;
import ModelPackage.Product;
import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class DAO {

    public static int ID = 0;
    public static int homeID = 0;

//    it will verify the user and redirect to the dashboard
    public static String verify(String username, String password) {
        Connection con = DBConnectionUtil.openConnection();
        String status = "error";
        try {
            String sql = "select * from user where username=? and password=?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setString(1, username);
            stmt.setString(2, password);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                ID = rs.getInt(5);
                if (rs.getString(4).compareTo("customer") == 0) {
                    status = "cust";
                }
                if (rs.getString(4).compareTo("admin") == 0) {
                    status = "adm";
                }
            }
            con.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return status;
    }

//    this class will intialize the values of customer class and we will use session to transfer the objects to extract the information from the class 
    public static Customer setCustomerClassValue() {
        Customer cust = new Customer("p", "p", "p");
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "select * from customer where custID = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1, ID);
            ResultSet result = stmt.executeQuery();
            while (result.next()) {
                homeID = result.getInt(5);
                cust.setName(result.getString(2));
                cust.setPhone(result.getString(3));
                cust.setMail(result.getString(4));
            }
            con.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        Home homee = setHomeClassValue();
        cust.setHome(homee);
        return cust;
    }

    //    this class will intialize the values of Admin class and we will use session to transfer the objects to extract the information from the class 
    public static Admin setAdminClassValue() {
        Admin adm = new Admin("p", "p", "p");
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "select * from admin where adminID = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1, ID);
            ResultSet result = stmt.executeQuery();
            while (result.next()) {
                adm.setName(result.getString(2));
                adm.setPhone(result.getString(3));
                adm.setEmail(result.getString(4));
            }
            con.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return adm;
    }

    //    this class will intialize the values of Home class and we will use session to transfer the objects to extract the information from the class 
    public static Home setHomeClassValue() {
        Home home = new Home("q", "q");
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "select * from home where homeID = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1, ID);
            ResultSet result = stmt.executeQuery();
            while (result.next()) {
                home.setHomeName(result.getString(2));
                home.setAddress(result.getString(3));
            }
            con.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return home;
    }

    public static List getAllCustomer() {
        List<Customer> cust = new ArrayList<>();
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "select * from customer";
            PreparedStatement stmt = con.prepareStatement(sql);
            ResultSet result = stmt.executeQuery();
            while (result.next()) {
                cust.add(new Customer(result.getString(2), result.getString(3), result.getString(4)));
            }
            con.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return cust;
    }

    public static List getAllHome() {
        List<Home> home = new ArrayList<>();
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "select * from home";
            PreparedStatement stmt = con.prepareStatement(sql);
            ResultSet result = stmt.executeQuery();
            while (result.next()) {
                home.add(new Home(result.getString(2), result.getString(3)));
            }
            con.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return home;
    }

    public static List getAllProduct() {
        List<Product> prod = new ArrayList<>();
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "select * from product";
            PreparedStatement stmt = con.prepareStatement(sql);
            ResultSet result = stmt.executeQuery();
            while (result.next()) {
                prod.add(new Product(result.getString(2), result.getDouble(3), result.getString(5)));
            }
            con.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return prod;
    }

    public static int deleteProduct(int a) {
        Connection con = DBConnectionUtil.openConnection();
        int i = 0;
        try {
            String sql = "delete from product where prodID = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1, a);
            i = stmt.executeUpdate();
            con.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return i;
    }
    
    
        public static int deleteCustomer(int a) {
        Connection con = DBConnectionUtil.openConnection();
        int i = 0;
        try {
            String sql = "delete from customer where custID = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1, a);
            i = stmt.executeUpdate();
            con.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return i;
    }

    public static void addProduct(int a, String b, double e, int c, String d) {
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "insert into product values(? ,? ,? ,? ,?)";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1, a);
            stmt.setString(2, b);
            stmt.setDouble(3, e);
            stmt.setString(5, d);
            stmt.setInt(4, c);
            int i = stmt.executeUpdate();
            con.close();
        } catch (Exception ee) {
            ee.printStackTrace();
        }
    }

    public static void addNewHome(String a, String b) {
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "insert into home values(? ,?)";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setString(1, a);
            stmt.setString(2, b);
            int i = stmt.executeUpdate();
            con.close();
        } catch (Exception ee) {
            ee.printStackTrace();
        }
    }
    
    public static void addNewUser(String a, String b) {
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "insert into user values(? ,?)";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setString(1, a);
            stmt.setString(2, b);
            int i = stmt.executeUpdate();
            con.close();
        } catch (Exception ee) {
            ee.printStackTrace();
        }
    }
    
    public static void addCustomer(int aa, String a, String b, String c, int d) {
        Connection con = DBConnectionUtil.openConnection();
        try {
            String sql = "insert into customer values(?, ? ,?, ?, ?)";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1, aa);
            stmt.setString(2, a);
            stmt.setString(3, b);
            stmt.setString(4, c);
            stmt.setInt(5, d);
            int i = stmt.executeUpdate();
            con.close();
        } catch (Exception ee) {
            ee.printStackTrace();
        }
    }
    
    
    
}
