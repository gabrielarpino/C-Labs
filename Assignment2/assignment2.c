#include "assignment2.h"

double calcAverageWaitingTime(struct Simulation * S)
{
	struct Queue Q;
	struct Data data;
	double wait, sum, res;
	int n;
	
	Q = S->eventQueue;
	sum = 0;
	n = Q.currSize;

	while(Q.currSize > 0){
		data = dequeue(&Q);
		wait = data.departureTime - data.arrivalTime;
		sum += wait;
	}
	
	res = sum/n;
	return res;
}

struct Simulation initSimulation(double arrivalRate, double serviceTime, double simTime)
{
	struct Simulation sim;
	double arrivalTime, departTime;
	
	arrivalTime = getRandTime(arrivalRate);
	sim.timeForNextArrival = arrivalTime;
	departTime = serviceTime + arrivalTime;
	sim.timeForNextDeparture = departTime;
	
	sim.currTime = 0.00;
	sim.arrivalRate = arrivalRate;
	sim.serviceTime = serviceTime;
	sim.totalSimTime = simTime;
	sim.buffer = initQueue();
	sim.eventQueue = initQueue();
	return sim;
}

double runSimulation(double arrivalRate, double serviceTime, double simTime)
{
	struct Simulation sim;
	struct Data temp;
	int e;

	sim = initSimulation(arrivalRate, serviceTime, simTime);

	while (sim.timeForNextDeparture < simTime) {
			if (sim.timeForNextArrival > sim.timeForNextDeparture && sim.buffer.currSize != 0) {
			sim.e = 1;
		}
		else {
			sim.e = 0;
		}
		e = sim.e;
		switch (e) {
/*Packet arriving*/
			case ARRIVAL:
				temp.arrivalTime = sim.timeForNextArrival;
				enqueue(&(sim.buffer), temp);
				sim.currTime = sim.timeForNextArrival;
				sim.timeForNextArrival += getRandTime(arrivalRate);
				break;
/*Packet departing*/						
			case DEPARTURE:
				temp = dequeue(&(sim.buffer));
				temp.departureTime = sim.timeForNextDeparture;
				sim.currTime = sim.timeForNextDeparture;
				if (sim.buffer.currSize != 0) {
					sim.timeForNextDeparture += serviceTime;
				}
				else {
					sim.timeForNextDeparture = sim.timeForNextArrival + serviceTime;
				}
				enqueue(&(sim.eventQueue), temp);
				break;
			}
		}
		
/*Freeing what was not departed from the queue*/
		while(sim.buffer.currSize > 0) {
			temp = dequeue(&(sim.buffer));
		}
/*Return average wait time*/
		return calcAverageWaitingTime(&sim);
		
}
