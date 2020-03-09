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
        <%
            List <Home> home = DAO.getAllHome();
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
                        <li><a class="dropdown-trigger" href="#!" data-target="dropdown1">
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
                    <li class="bordered"><a class="waves-effect" href="#!"><i class="material-icons">build</i>My Profile</a></li>
                </ul>
            </div>
            <div class="container admin-content">
                <div class="col s12 m12 l9 offset-l3">
                    <div class="hero-title">Customer Profile Page</div>
                    <div class="divider"></div>
                    <div class="admin-content">
                        <div class="col s12 m12 l8">
                            <div class="card">
                                <div class="card-content row">
                                    <h6><b>Customer Details</b></h6>
                                    <div class="divider"></div>
                                    <br>
                                    <table class="table table-borderless">
                                        <tr>
                                            <th scope="row">Name : </th>
                                            <td>${custSession.name}</td>
                                        </tr>
                                        <tr>
                                            <th scope="row">Phone : </th>
                                            <td>${custSession.phone}</td>
                                        </tr>
                                        <tr>
                                            <th scope="row">Email : </th>
                                            <td>${custSession.mail}</td>
                                        </tr>
                                        <tr>
                                            <th scope="row">Home Name : </th>
                                            <td>Yeasin Home</td>
                                        </tr>
                                        <tr>
                                            <th scope="row">Home Address : </th>
                                            <td>KDOJ XB2</td>
                                        </tr>
                                    </table>
                                    <br>
                                    <div class="center-align">
                                        <a class="waves-effect waves-light btn">Edit</a>
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