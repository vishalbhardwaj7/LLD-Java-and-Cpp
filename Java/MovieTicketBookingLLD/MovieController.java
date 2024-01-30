package MovieTicketBookingLLD;

import MovieTicketBookingLLD.Enums.City;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class MovieController {
    Map<City,List<Movie>> cityVsMovies;
    List<Movie> allMovies;

    MovieController(){
        cityVsMovies=new HashMap<>();
        allMovies=new ArrayList<>();
    }
    // add movie to a particular city, make use of cityvsMovies map
    void addMovie(Movie movie, City city){
        allMovies.add(movie);

        List<Movie> movies = cityVsMovies.getOrDefault(city, new ArrayList<>());
        movies.add(movie);
        cityVsMovies.put(city,movies);
    }

    Movie getMovieByName(String movieName){
        for(Movie movie: allMovies){
            if(movie.getMovieName().equals(movieName)){
                return movie;
            }
        }
        return null;
    }
    List<Movie> getMoviesByCity(City city){
        return cityVsMovies.get(city);
    }
}
