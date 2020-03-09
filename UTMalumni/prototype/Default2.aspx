<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        
        <div>
            <center>
                <h1> 
                    Search Records From The Database
                </h1>
                <h2>
                    Display In Grid View Controller
                </h2>
                <hr />
            
            Search : <asp:TextBox ID="Txtsearch" runat="server"></asp:TextBox>
            <asp:Button ID="Buttonsearch" runat="server" Text="Button" OnClick="Buttonsearch_Click" />
            <hr />
               
            <asp:GridView ID="dataTable" runat="server" ShowheaderWhenEmpty="true" EmptyDataText="No Records Found!">
        </asp:GridView>
                 </center>
        </div>
    </form>
</body>
</html>
