
package ModelPackage;

/**
 *
 * @author mesba
 */
public class Customer implements java.io.Serializable {
    private String name;
    private String phone;
    private String mail;
    private Home home;

    public Customer() {
    }

    
    public Customer(String name, String phone, String mail) {
        this.name = name;
        this.phone = phone;
        this.mail = mail;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getMail() {
        return mail;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }
    
    public void setHome(Home home){this.home = home;}
    
    public String getHomeName(){return this.home.getHomeName();}
    public String getHomeAddress(){return this.home.getAddress();}
    
}
