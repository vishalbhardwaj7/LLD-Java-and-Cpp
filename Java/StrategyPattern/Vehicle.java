public class Vehicle{
    DriveStrategy driveObject;
    //this is known as constructor injection it will take constructor of whatever strategy type we pass
    Vehicle(DriveStrategy driveObject){
        this.driveObject=driveObject;
    }
    public void drive(){
        driveObject.drive();
    }
}