package MovieTicketBookingLLD;

public class Movie {
    int movieId;
    String movieName;
    int movieDurationInMinutes;
    //other details like genre,language etc
    public int getMovieId(){
        return movieId;
    }
    public void setMovieId(int movieId){
        this.movieId=movieId;
    }
    public String getMovieName(){
        return movieName;
    }
    public void setMovieName(String name){
        this.movieName=name;
    }
    public int getMovieDuration(){
        return movieDurationInMinutes;
    }
    public void setMovieDuration(int movieDuration){
        this.movieDurationInMinutes=movieDuration;
    }
}
