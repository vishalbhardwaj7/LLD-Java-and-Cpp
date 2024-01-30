package NullObjectPatternLLD;

public class NullVehicle implements Vehicle {
    @Override
    public int getTankCapacity(){
        return 0;//default behavior
    }
    @Override
    public int getSeatingCapacity(){
        return 0;//default behavior
    }
}