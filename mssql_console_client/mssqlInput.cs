using System;
using System.Data.SqlClient;

namespace ConsoleApp
{
    class Program
    {

        
        static void Main(string[] args)
        {

            Console.WriteLine("Enter id:");
            int id = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter post:");
            string post = Console.ReadLine();

            string connectionString = "Persist Security Info=False;Trusted_Connection=True; database=mydb;server=(local)";
            
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                
                string query = "INSERT INTO dbo.t1 (id, post) VALUES (@id, @post)";
                
                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@id", id); // значение id
                    command.Parameters.AddWithValue("@post", post); // значение post
                    
                    command.ExecuteNonQuery();
                }
            }
            
            Console.WriteLine("Запись успешно добавлена в базу данных.");
            Console.ReadLine();
        }
    }
}