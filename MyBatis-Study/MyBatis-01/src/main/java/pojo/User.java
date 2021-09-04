package pojo;

public class User {
    private String username;
    private String password;
    private String customer_no;

    public User() {
    }

    public User(String username, String password, String customer_no) {
        this.username = username;
        this.password = password;
        this.customer_no = customer_no;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getCustomer_no() {
        return customer_no;
    }

    public void setCustomer_no(String customer_no) {
        this.customer_no = customer_no;
    }

    @Override
    public String toString() {
        return "User{" +
                "username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", customer_no='" + customer_no + '\'' +
                '}';
    }
}
