class SportsVehicle extends Vehicle{
    SportsVehicle(){super(new SportsDriveStrategy());}//with super i call vehicle cons and pass sport strategy
}