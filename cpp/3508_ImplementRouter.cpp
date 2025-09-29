#include <bits/stdc++.h>

class Router
{
    using Packet = std::tuple<int, int, int>;

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {};

    bool addPacket(int source, int destination, int timestamp)
    {
        auto packetToAdd = std::make_tuple(source, destination, timestamp);

        const auto [_, insertionSucceeded] = packetSet.insert(packetToAdd);

        if (not insertionSucceeded)
        {
            // duplicated packet
            return false;
        }

        ++memoryState;

        if (memoryState > memoryLimit)
        {
            forwardPacket();
        }

        packetOrder.push_back(packetToAdd);
        packetMap[destination].push_back(timestamp);
        return true;
    }

    std::vector<int> forwardPacket()
    {
        if (packetOrder.size() == 0)
            return std::vector<int>();
        auto packetToForward{packetOrder.front()};
        packetSet.erase(packetToForward);
        packetMap[std::get<1>(packetToForward)].pop_front();
        packetOrder.pop_front();
        memoryState--;
        return std::vector<int>{std::get<0>(packetToForward),
                                std::get<1>(packetToForward),
                                std::get<2>(packetToForward)};
    }

    int getCount(int destination, int startTime, int endTime)
    {
        const auto &packetList{packetMap[destination]};
        if (packetList.size() == 0)
            return 0;
        return std::upper_bound(packetList.begin(),
                                packetList.end(),
                                endTime) -
               std::lower_bound(packetList.begin(), packetList.end(), startTime);
    }

private:
    size_t memoryLimit;
    size_t memoryState{0};
    std::set<Packet> packetSet;
    std::deque<Packet> packetOrder{};
    std::unordered_map<int, std::deque<int>> packetMap{};
};