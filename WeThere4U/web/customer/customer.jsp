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
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Customer Dashboard</title>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons|Poppins">
        <link rel="stylesheet" href="style.css">

        <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
        <script src="script.js"></script>
    </head>
    <body>
        <%--<jsp:useBean id="custom" scope="session" class="ModelPackage.Customer"/>--%>
        <% List <Product> lp = DAO.getAllProduct();%>
        <ul id="dropdown1" class="dropdown-content">
            <li><a href="custProfile.jsp"><i class="material-icons">build</i>Account Settings</a></li>
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
                        <li><a class="dropdown-trigger" href="#!" data-target="dropdown1">
                                <%--<jsp:getProperty name="custom" property="name"/>--%>
                                ${custSession.name}
                                <i class="material-icons right">arrow_drop_down</i></a></li>
                    </ul>
                </div>
            </nav>
        </div>
        <div class="row">
            <div class="col s12 m12 l3">
                <ul id="slide-out" class="sidenav sidenav-fixed sidebar-clear-parent">
                    <li class="sidebar-clear"></li>
                    <li class="img-thumb valign-wrapper">
                        <img src="./yeasin.jpg" class="circle" alt="" height="150" width="150">
                    </li>
                    <li class="bordered"><a class="waves-effect" href="#!"><i class="material-icons">dashboard</i>RIP Sensor</a></li>
                    <li class="bordered"><a class="waves-effect" href="#!"><i class="material-icons">star</i>Temperature Sensor</a></li>
                    <li class="bordered"><a class="waves-effect" href="#!"><i class="material-icons">photo_library</i>Humidity Sensor</a></li>
                    <li class="bordered"><a class="waves-effect" href="#!"><i class="material-icons">storage</i>Bought Products</a></li>
                    <li class="bordered"><a class="waves-effect" href="custProfile.jsp"><i class="material-icons">build</i>My Profile</a></li>
                </ul>
            </div>
            <div class="container admin-content">
                <div class="col s12 m12 l9 offset-l3">
                    <div class="hero-title">Customer Dashboard Page</div>
                    <div class="divider"></div>
                    <div class="admin-content">
                        <div class="col s12 m12 l8">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Home Status</b><p>
                                        <br>
                                    <h5><b><%="Your Home is Safe"%></b> </h5>
                                    <br>
                                    <br>
                                    <br>
                                </div>
                            </div>
                        </div>
                        <div class="col s12 m12 l4">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Humidity</b></p>
                                    <br>
                                    <h3 class="text-center"><%="45"%>%</h3>
                                    <br>
                                    <div class="right-align">
                                        <a class="waves-effect waves-light btn">Manage</a>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="col s12 m12 l8">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Bought Products</b></p>
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
                        <div class="col s12 m12 l4">
                            <div class="card">
                                <div class="card-content">
                                    <p><b>Temperature</b></p>
                                    <br>
                                    <h3 class="text-center"><b><%="23"%>&#8451;</b></h3>
                                    <br>
                                    <div class="right-align">
                                        <a class="waves-effect waves-light btn">Manage</a>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>



