package NullObjectPatternLLD;

public class VehicleFactory {
    static Vehicle getVehicleObject(String x){
        if("Car".equals(x))
            return new Car();
        return new NullVehicle();//default case //null object replaced the null return type
    }
}
