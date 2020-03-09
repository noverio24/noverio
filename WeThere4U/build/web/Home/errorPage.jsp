<%-- 
    Document   : errorPage
    Created on : Jan 7, 2020, 1:33:09 AM
    Author     : mesba
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Error Page</title>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
    </head>
    <body style="padding-top: 10%;">
        <div class="container" >
        <div class="row align-items-end">
    <div class="col " style="padding-bottom: 20%;">
        <p><b>One of the things go wrong</b></p>
        <ul>
            <li>invalid username</li>
            <li>invalid password</li>
            <li>connection is reset</li>
        </ul>
        
        <a href="index.html">
            <button type="button" class="btn btn-warning">Warning</button>
        </a>
    </div>
    <div class="col">
        <img src="./images/errorPage.png"   height="500" width="700">
    </div>
  </div>
        </div>
    </body>
</html>
