#include<bits/stdc++.h>
using namespace std;

enum SeatCategory{
    SILVER,PLATINUM,GOLD
};


class Seat{
    int id;
    SeatCategory category;
    int row;
    int col;
};

class Screen{
    vector<Seat*> seats;
    int id;
};

class Movie{
    int id;
    string name;
    int duration;
};

class City{
    string name;
};

class MovieController{
    unordered_map<City*,vector<Movie>> cityVsMovies;
    vector<Movie*> movies;

    //
    Movie getMovieByName(string movie){
        //iteraate over movies and return movie object
    }

    //
    vector<Movie> getMoviesByCity(City * city){
        return cityVsMovies[city];
    }
};

class Time{
    int day,month, year, hours, second, minutes;
};

class Show{
public:
    int showId;
    Movie movie;
    Screen screen;
    Time showTime;
    int showDuration;
    vector<Seat> bookedSeats;// array to check if seat is booked or not
};

class Address{
    string house;
    string pincode;
    ///// etc/////////////
};

class Theatre{
public:
    vector<Screen*> screens;
    vector<Show*> shows;
    int theatreID;
    Address address;
    City city;
    int id;
};


class TheatreController{
    vector<Theatre*> theatres;
    unordered_map<City*,vector<Theatre>> cityVsTheatres;

    //CRUDS

    map<Theatre,vector<Show>> getListOfShowsPerTheatre(City *city, Movie *desiredmovie){
        //functionm to get Theatree wise shows
        //1. get theatre
        vector<Theatre> theatres = cityVsTheatres[city];
        map<Theatre,vector<Show*>> result;
        for(auto theatre:theatres){
            //iterate over all shows of that theatre 
            for(auto show: theatre.shows){
                if(show.movie == desiredmovie)
                    result[theatre].push_back(show);//push the show in that categoruy
            }
        }
    }
};

class Booking{
    Show show;
    vector<Seat> bookedSeats;
    Payment payment;
};

class Payment{
    Status status;
    int id;
}
;

int main(){
    //1. fill up all the objects 
    //2. make movies 
    //3. make seats
    //4. fill seats in screen
    //5. make shows
    //6. make theatres
    //7. map all things

    // make controller objects

    // Main flow

    // user comes
    // selects a city
    // get city wise movies
    // let him chose a movie
    // now use getListOfShowsPerTheatre function to fetch all shows theatre wise in that city for that movie

    // now he can just create a booking
    // iterate of booked seats of that show and make a booking 

    // make payment
    // for that time reserve the seats
    // now is payment is ok book the seats by inseerting in booked seats array of that show
    // it is done now




}


//concurreny handling
//Seat 1
//User 1 and User 2
//Both cant get same number
//if user 1 select seat 1 and not pay for 10 mins till that time this seat can't be filled for 



//2 type of concurrency handling
//1. optimistic -> (it allows multiple user to do the read , at the time of update it checks the version of object (lets say v1 of seat) so it checks if the version is still v1 so it will take lock change verison to v2 then release it. so when user2 will read it will see version2 so it wont be able to update)
//2. pessimistic -> whenever we read, lock that time only (if user 1 read only that time lock, so user 2 can't lock also. When update the release lock)


//Which lock we will chose ?

//When reading the seats if i lock it pessimistic then if traffic is more so all seats will get lock
//optimistic is best way in this case

//we will maintain a particular version of a Seat
// user 1    |    user 2
//   read v1 |    read v1
//           |    
//           |    
//           |    
//           |    
//           |    
//           |    
//           |    
//           |    
          
//           seat update operation is in synchronized block
//           so only one can go in 
          //if user 1 goes in, it checks that currently version is v1
          //so it update and book it and update it to v2
          //then release the lock
          //now user 2 goes in
          //it sees version is v2 (not v1)
          //so can't update




          //2nd issue is to solve timer problem
          //so will use redis to give timer to  the lock. 
          //so after this time it will automatically release
          
          