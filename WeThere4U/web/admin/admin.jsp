<%-- 
    Document   : admin
    Created on : Dec 26, 2019, 9:34:28 PM
    Author     : Yeasin
--%>

<%@page import="ModelPackage.Product"%>
<%@page import="ModelPackage.Home"%>
<%@page import="java.util.List"%>
<%@page import="ModelPackage.Customer"%>
<%@page import="Databse.DAO"%>
<%@page import="ModelPackage.Admin"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Admin Dashboard</title>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons|Poppins">
        <link rel="stylesheet" href="style.css">

        <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
        <script src="script.js"></script>
    </head>
    <body>
        <%
            Admin admin = (Admin) session.getAttribute("adminSession");
            List<Customer> cust = DAO.getAllCustomer();
            List<Home> home = DAO.getAllHome();
            List<Product> lp = DAO.getAllProduct();
        %>
        <ul id="dropdown1" class="dropdown-content">
            <li><a href="style.css"><i class="material-icons">build</i>Account Settings</a></li>
            <li><a href="../LogOutAdminController"><i class="material-icons">logout</i>Logout</a></li>
        </ul>
        <div class="navbar-fixed">
            <nav class="colored">
                <div class="nav-wrapper">
                    <ul class="right hide-on-large-only show-on-medium-and-down">
                        <li>
                            <a href="#" data-target="slide-out" class="sidenav-trigger"><i class="material-icons">menu</i></a>
                        </li>
                    </ul>
                    <ul class="right hide-on-med-and-down">
                        <li><a class="dropdown-trigger" href="#!" data-target="dropdown1"><%=admin.getName()%><i class="material-icons right">arrow_drop_down</i></a></li>
                    </ul>
                </div>
            </nav>
        </div>
        <div class="row">
            <div class="col s12 m12 l3">
                <ul id="slide-out" class="sidenav sidenav-fixed sidebar-clear-parent">
                    <li class="sidebar-clear"></li>
                    <li class="img-thumb valign-wrapper">
                        <img src="./norizam.jpg" class="circle" alt="" height="150" width="150">
                    </li>
                    <li class="bordered"><a class="waves-effect" href="admin.jsp"><i class="material-icons">dashboard</i>Dashboard</a></li>
                    <li class="bordered"><a class="waves-effect" href="customerAdmin.jsp"><i class="material-icons">star</i>Customers</a></li>
                    <li class="bordered"><a class="waves-effect" href="addNewCustomer.jsp"><i class="material-icons">photo_library</i>Add New Customer</a></li>
                    <li class="bordered"><a class="waves-effect" href="productAdmin.jsp"><i class="material-icons">storage</i>Product</a></li>
                    <li class="bordered"><a class="waves-effect" href="#!"><i class="material-icons">build</i>Setting Page</a></li>
                </ul>
            </div>
            <div class="container admin-content">
                <div class="col s12 m12 l9 offset-l3">
                    <div class="hero-title">Admin Dashboard Page</div>
                    <div class="divider"></div>
                    <div class="admin-content">
                        <div class="col s12 m12 l4">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Total Customer</b></p>
                                    <br>
                                    <h3 class="text-center"><b><%="23"%></b></h3>
                                    <br>
                                </div>
                            </div>
                        </div>
                        <div class="col s12 m12 l4">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Total Product Sale</b></p>
                                    <br>
                                    <h3 class="text-center"><b><%="23"%></b></h3>
                                    <br>
                                </div>
                            </div>
                        </div>
                        <div class="col s12 m12 l4">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Total Earnings</b></p>
                                    <br>
                                    <h3 class="text-center"><b><%="RM 12000"%></b></h3>
                                    <br>
                                </div>
                            </div>
                        </div>
                        <div class="col s12 m12 l4">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>New Visitor</b></p>
                                    <br>
                                    <h3 class="text-center"><b><%="23"%></b></h3>
                                    <br>
                                </div>
                            </div>
                        </div>
                        <div class="col s12 m12 l4">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Advertisement Cost</b></p>
                                    <br>
                                    <h3 class="text-center"><b><%="RM 2300"%></b></h3>
                                    <br>
                                </div>
                            </div>
                        </div>
                        <div class="col s12 m12 l4">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Agents Cost</b></p>
                                    <br>
                                    <h3 class="text-center"><b><%="RM 3999"%></b></h3>
                                    <br>
                                </div>
                            </div>
                        </div>
                        
                        <div class="col s12 m12 l12">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Customers List</b></p>
                                    <div class="divider"></div>
                                    <table class="table table-striped">
                                        <thead>
                                            <tr>
                                                <th scope="col">#</th>
                                                <th scope="col">Name</th>
                                                <th scope="col">Phone</th>
                                                <th scope="col">Email</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                            <%for (int i = 0; i < cust.size(); i++) {%>
                                            <tr>
                                                <th scope="row"><%=i + 1%></th>
                                                <td><%=cust.get(i).getName()%></td>
                                                <td><%=cust.get(i).getPhone()%></td>
                                                <td><%=cust.get(i).getMail()%></td>
                                            </tr>
                                            <%}
                                            %>
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        </div>
                        <div class="col s12 m12 l12">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Products List</b></p>
                                    <div class="divider"></div>
                                    <table class="table table-borderless">
                                        <thead>
                                            <tr>
                                                <th scope="col">#</th>
                                                <th scope="col">Product Name</th>
                                                <th scope="col">Price</th>
                                                <th scope="col">Sensor's Name</th>
                                            </tr>
                                        </thead>
                                        <tbody>

                                            <%for (int i = 0; i < lp.size(); i++) {%>
                                            <tr>
                                                <th scope="row"><%=i + 1%></th>
                                                <td><%=lp.get(i).getProdName()%></td>
                                                <td><%=lp.get(i).getPrice()%></td>
                                                <td><%=lp.get(i).getSensorName()%></td>
                                            </tr>
                                            <%}
                                            %>
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        </div>                       
                        <div class="col s12 m12 11">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Homes List</b></p>
                                    <div class="divider"></div>
                                    <table class="table table-striped">
                                        <thead>
                                            <tr>
                                                <th scope="col">#</th>
                                                <th scope="col">Home Owner</th>
                                                <th scope="col">Home Address</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                            <%for (int i = 0; i < home.size(); i++) {%>
                                            <tr>
                                                <th scope="row"><%=i + 1%></th>
                                                <td><%=home.get(i).getHomeName()%></td>
                                                <td><%=home.get(i).getAddress()%></td>
                                            </tr>
                                            <%}
                                            %>
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>



