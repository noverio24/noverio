using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Configuration;

public partial class Default2 : System.Web.UI.Page
{
    
    protected void Page_Load(object sender, EventArgs e)
    {
       
    }

    protected void Buttonsearch_Click(object sender, EventArgs e)
    {
        string mainconn = ConfigurationManager.ConnectionStrings["Demo_FC_ALISConnectionString"].ConnectionString;
        SqlConnection sqlconn = new SqlConnection(mainconn);
        sqlconn.Open();
        SqlCommand sqlcomm = new SqlCommand();
        string sqlquery = "select * from [dbo].[FindCompanyDa] where Companytypes like '%'+@Companytypes+'%'";
        sqlcomm.CommandText = sqlquery;
        sqlcomm.Connection = sqlconn;
        sqlcomm.Parameters.AddWithValue("Companytypes", Txtsearch.Text);
        DataTable dt = new DataTable();
        SqlDataAdapter sda = new SqlDataAdapter(sqlcomm);
        sda.Fill(dt);
        dataTable.DataSource = dt;
        dataTable.DataBind();
    }
}