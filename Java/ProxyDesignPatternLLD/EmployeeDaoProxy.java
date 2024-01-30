package ProxyDesignPatternLLD;
//proxy

public class EmployeeDaoProxy implements EmployeeDao {
    EmployeeDaoImpl employeeDaoObj = new EmployeeDaoImpl();//it has a relation ship with dao object
    @Override
    public void create(String client, EmployeeDo obj)throws Exception{
        if(client.equals("ADMIN")){
            System.out.println("reached proxy ");
            try{
                employeeDaoObj.create(client, obj);
            }
            catch(Exception e){
                System.out.println("inside catch block ");
                System.out.println(e);
            }
            System.out.println("reached proxy ");
            return;
        }
        //create a new row
        throw new Exception("Access Denied");
    }
    @Override
    public void delete(String client, int employeeId)throws Exception{
        //delete a row
        if(client.equals("ADMIN")){
            employeeDaoObj.delete(client, employeeId);
            return;
        }
        throw new Exception("Access Denied");
    }
    @Override
    public EmployeeDo get(String client, int employeeId)throws Exception{
        if(client.equals("ADMIN") || client.equals("USER")){
            return employeeDaoObj.get(client, employeeId);
        }
        throw new Exception("Access Denied");
    }
}
