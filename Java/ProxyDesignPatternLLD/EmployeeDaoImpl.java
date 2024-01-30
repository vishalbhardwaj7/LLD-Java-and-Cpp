package ProxyDesignPatternLLD;

public class EmployeeDaoImpl implements EmployeeDao {
    @Override
    public void create(String client, EmployeeDo obj)throws Exception{
        //create a new row
        System.out.println("created a new row");
        return;
    }
    @Override
    public void delete(String client, int employeeId)throws Exception{
        //delete a row
        System.out.println("deleted a row"+ employeeId);
    }
    @Override
    public EmployeeDo get(String client, int employeeId)throws Exception{
        System.out.println("fetching data from db");
        return new EmployeeDo();
    }
}
