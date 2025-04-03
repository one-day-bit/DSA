#include <iostream>
#include "queue.hpp"
#include "stack.hpp"
#include "graph.hpp"
#include <cstring> // for strcpy
using namespace std;
void clearInputBuffer()
{
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }
}

int main()
{
    GasStationGraph gasNetwork;
    int choice;

    do
    {
        cout << "\n===== GAS STATION TRACKER MENU =====\n";
        cout << "1. Add a new gas station\n";
        cout << "2. Add connection between stations\n";
        cout << "3. Find nearest gas station\n";
        cout << "4. Find shortest path between stations\n";
        cout << "5. Find cheapest gas station\n";
        cout << "6. Update fuel price\n";
        cout << "7. Delete gas station\n";
        cout << "8. Delete connection\n";
        cout << "9. Display all gas stations\n";
        cout << "10. Display all connections\n";
        cout << "11. Save data\n";
        cout << "12. Load data\n";
        cout << "13. Display network\n";
        cout << "14. Perform DFS traversal\n";
        cout << "15. Perform BFS traversal\n";
        cout << "16. Find cheapest gas in range\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number: ";
            clearInputBuffer();
        }
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        {
            char name[50];
            double price;

            cout << "Enter station name: ";
            cin.getline(name, 50);
            cout << "Enter gas price: $";
            while (!(cin >> price) || price <= 0)
            {
                cout << "Invalid price. Please enter a positive number: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.addStation(name, price);
            break;
        }

        case 2:
        {
            int source, dest;
            double distance;

            gasNetwork.displayAllStations();

            cout << "Enter source station ID: ";
            while (!(cin >> source))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            cout << "Enter destination station ID: ";
            while (!(cin >> dest))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            cout << "Enter distance between stations (miles): ";
            while (!(cin >> distance) || distance <= 0)
            {
                cout << "Invalid distance. Please enter a positive number: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.addConnection(source, dest, distance);
            break;
        }

        case 3:
        {
            int stationId;
            gasNetwork.displayAllStations();

            cout << "Enter station ID to find nearest: ";
            while (!(cin >> stationId))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            int nearest = gasNetwork.findNearestStation(stationId);
            if (nearest == -1)
            {
                cout << "No connected stations found.\n";
            }
            else
            {
                cout << "Nearest station is " << nearest << ": " << gasNetwork.getStationName(nearest) << "\n";
            }
            break;
        }

        case 4:
        {
            int start, end;
            gasNetwork.displayAllStations();

            cout << "Enter starting station ID: ";
            while (!(cin >> start))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            cout << "Enter destination station ID: ";
            while (!(cin >> end))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.findShortestPath(start, end);
            break;
        }

        case 5:
        {
            int cheapest = gasNetwork.findCheapestStation();
            if (cheapest == -1)
            {
                cout << "No stations in the network.\n";
            }
            else
            {
                cout << "Cheapest gas station is ID " << cheapest << ": "
                     << gasNetwork.getStationName(cheapest) << " ($"
                     << gasNetwork.getStationPrice(cheapest) << ")\n";
            }
            break;
        }

        case 6:
        {
            int stationId;
            double newPrice;

            gasNetwork.displayAllStations();

            cout << "Enter station ID to update: ";
            while (!(cin >> stationId))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            cout << "Enter new gas price: $";
            while (!(cin >> newPrice) || newPrice <= 0)
            {
                cout << "Invalid price. Please enter a positive number: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.updateFuelPrice(stationId, newPrice);
            break;
        }

        case 7:
        {
            int stationId;
            gasNetwork.displayAllStations();

            cout << "Enter station ID to delete: ";
            while (!(cin >> stationId))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.deleteStation(stationId);
            break;
        }

        case 8:
        {
            int source, dest;
            gasNetwork.displayAllConnections();

            cout << "Enter source station ID: ";
            while (!(cin >> source))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            cout << "Enter destination station ID: ";
            while (!(cin >> dest))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.deleteConnection(source, dest);
            break;
        }

        case 9:
            gasNetwork.displayAllStations();
            break;

        case 10:
            gasNetwork.displayAllConnections();
            break;

        case 11:
            gasNetwork.saveData();
            break;

        case 12:
            gasNetwork.loadData();
            break;

        case 13:
            gasNetwork.displayNetwork();
            break;

        case 14:
        {
            int startStation;
            gasNetwork.displayAllStations();

            cout << "Enter starting station ID: ";
            while (!(cin >> startStation))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.DFS(startStation);
            break;
        }

        case 15:
        {
            int startStation;
            gasNetwork.displayAllStations();

            cout << "Enter starting station ID: ";
            while (!(cin >> startStation))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.BFS(startStation);
            break;
        }

        case 16:
        {
            int startStation, maxHops;
            gasNetwork.displayAllStations();

            cout << "Enter starting station ID: ";
            while (!(cin >> startStation))
            {
                cout << "Invalid ID. Please enter a valid station ID: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            cout << "Enter maximum number of hops: ";
            while (!(cin >> maxHops) || maxHops < 1)
            {
                cout << "Invalid number. Please enter a positive integer: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            gasNetwork.findCheapestInRange(startStation, maxHops);
            break;
        }

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}