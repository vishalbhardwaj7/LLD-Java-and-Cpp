package NullObjectPatternLLD;

public class Main {
    public static void main(String args[]){
        Vehicle vehicle = VehicleFactory.getVehicleObject("Bike");
        printVehicleDetails(vehicle);
    }
    private static void printVehicleDetails(Vehicle vehicle){
        if(vehicle!=null){
            System.out.println("vehicle estating capacity is"+ vehicle.getSeatingCapacity());
            System.out.println("fuel tank capacity is"+ vehicle.getTankCapacity());
        }
        //without if case also no exception
        System.out.println("vehicle estating capacity is"+ vehicle.getSeatingCapacity());
        System.out.println("fuel tank capacity is"+ vehicle.getTankCapacity());
    }
}