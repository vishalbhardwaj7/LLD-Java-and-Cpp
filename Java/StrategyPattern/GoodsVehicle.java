class GoodsVehicle extends Vehicle{
    GoodsVehicle(){super(new NormalDriveStrategy());}//with super i call vehicle cons and pass sport strategy
}