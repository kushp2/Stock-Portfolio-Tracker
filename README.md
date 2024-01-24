About this project:
This program will allow the user to access real time stock market data and update a portfolio. 
This is a personal project to show my proficiency in SQL, C++ and the .NET framework, and Windows Forms to develop the UI.
The stocks.exe only runs on x64 systems, compile the code in visual studio with your systems propper settings to produce stocks.exe if the provided executable doesn't work. 

WARNING:
This program uses the free version of Alpha Vantage for the external stock market API. Because it's the free version, it only allows 25 api calls per 24 hours. Each stock search is one api call, and the update button calls the API once per stock in the user's portfolio.

How the pogram works:
The program will open a Windows Form promting the user for a username and the option to: create an account, login, or delete account. 
Once the account is logged into (or an account is created), it will close the Form and open another Windows Form containing the user's portfolio.
From there, the user can search up Stocks based on their symbol, and the program will output the stock's information. The user can input a quantity of said stock, then choose to "add" or "remove" them from the users portfolio.
The portfolio box on the right will output all the user's stocks from their portfolio. It will prompt the user to "save their portfolio". 
The user can "update" the portfolio, which will update the "Current Price" of the displayed stocks. The user can also select "Save" which will save the portfolio to the database.

Database Format:
One table that holds the Usernames, the date the account was created, and an incrementing primary key.
One table per username in the Usernames Table that holds the associated user's stock portfolio data. Holds the stock's: Symbol, Current Price, Buy Price, and Quantity. 


Misc. Infor:
The Stock class (Stock.cpp and Stock.h) is currently unused, it was the first class I made for this project. It was meant to be a stock object holding the necessary data, but became obsolete when I implemented databases.
