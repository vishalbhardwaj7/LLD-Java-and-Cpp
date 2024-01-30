package MovieTicketBookingLLD;
import MovieTicketBookingLLD.Enums.City;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;



public class TheatreController {
    Map<City,List<Theatre>> cityVsTheatre;// has->a Theatre
    List<Theatre> allTheatres;

    TheatreController() {
        cityVsTheatre = new HashMap<>();
        allTheatres = new ArrayList<>();
    }


    void addTheatre(Theatre theatre, City city){
        allTheatres.add(theatre);
        List<Theatre> theatres = cityVsTheatre.getOrDefault(city, new ArrayList<>());
        theatres.add(theatre);
        cityVsTheatre.put(city, theatres);
    }

    //provided a movie and a city it will give all shows per theatre of that movie
    Map<Theatre,List<Show>> getAllShow(Movie movie, City city){
        //get all theatre of this city
        Map<Theatre,List<Show>> theatreVsShows=new HashMap<>();
        List<Theatre> theatres=cityVsTheatre.get(city);

        //filter the theatres which run this movie
        for(Theatre theatre:theatres){
            List<Show> givenMovieShows = new ArrayList<>();
            List<Show> shows = theatre.getShows();
            for(Show show:shows){
                if(show.movie.getMovieId()==movie.getMovieId()){
                    givenMovieShows.add(show);
                }
            }
            if(!givenMovieShows.isEmpty()){
                theatreVsShows.put(theatre, givenMovieShows);
            }

        }
        return theatreVsShows;
    }
}
