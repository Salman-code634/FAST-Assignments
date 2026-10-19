#include <iostream>
#include <cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){

    int choice;
    cout << "Enter a number: ";
    cin>> choice;

    switch(choice){
        case 1:
        {
            // Declare variables
            int type, game, timeLeft, guardAlert, inguries, lightsOn, cameras, takeNeedles, needles,takeBandages;
            int bandages, takeMarbles, marbles, takeRope, ropeM, packKg, stamina, playersLeft, bet, stake,favor;
            int cash, debt, card, ally;
            int marblePrice = 60, bandagePrice = 350, ropePrice = 120, needlePrice = 150;
            int marbleCost, bandageCost, ropeCost, needleCost;
            int dneedles, dneedlePrice, dneedleCost, ftneedleCost;
            int dmarbles, dmarblePrice, dmarbleCost, ffmarbleCost;
            int dbandages;
            int alertAdj;
            int Crowd, Alert, Cameras = 0, Darkness = 0, Game, TotalDangerPoints;
            int surchargePct, NeedleS, MarblesS, BandagesS, RopeS, itemsAfterSurcharge;
            int lateFee, GuardToll, carryCap, weightPenalty, wager;
            int allyRebate, calmRebate, injuryTax;
            int favorDiscount = 0;
            int gross, net, debtFee, Total, fees, cashUsed, payable;
            int survivalChance = 40, outcome;
            int prizePool, prizeShare, betPayout, finalBalance;
            
            
            //take inputs
            cout<<"Enter type: ";
            cin>>type;

            cout<<"Enter game: ";
            cin>>game; 

            cout<<"Enter time left: ";
            cin>>timeLeft; 

            cout<<"Enter guard alert: ";
            cin>>guardAlert;

            cout<<"Enter injuries: ";
            cin>>inguries; 

            cout<<"Enter lights on: ";
            cin>>lightsOn; 

            cout<<"Enter cameras: ";
            cin>>cameras;

            cout<<"Enter take needles: ";
            cin>>takeNeedles;  

            cout<<"Enter needles: ";
            cin>>needles;

            cout<<"Enter take bandages: ";
            cin>>takeBandages;

            cout<<"Enter bandages: ";
            cin>>bandages;  

            cout<<"Enter take marbles: ";
            cin>>takeMarbles;

            cout<<"Enter marbles: ";
            cin>>marbles;  

            cout<<"Enter take rope: ";
            cin>>takeRope;

            cout<<"Enter rope: ";
            cin>>ropeM;

            cout<<"Enter pack kg: ";
            cin>>packKg;

            cout<<"Enter stamina: ";
            cin>>stamina;

            cout<<"Enter players left: ";
            cin>>playersLeft;

            cout<<"Enter bet: ";
            cin>>bet;   

            cout<<"Enter stake: ";
            cin>>stake;

            cout<<"Enter favor: ";
            cin>>favor;

            cout<<"Enter cash: ";
            cin>>cash;

            cout<<"Enter debt: ";
            cin>>debt;

            cout<<"Enter card: ";
            cin>>card;

            cout<<"Enter ally: ";
            cin>>ally;

            //Validate inputs
            

            ((type == 65 || type == 84 || type == 71) && (game >= 1 && game <= 5) && (timeLeft >= 0 && timeLeft <= 120)
            && (guardAlert >= 0 && guardAlert <= 100) && (inguries >= 0 && inguries <= 3) && (lightsOn == 0 || lightsOn == 1)
            && (cameras == 0 || cameras == 1) && (takeNeedles == 0 || takeNeedles == 1) && (needles >= 0 && needles <= 40)
            && (takeBandages == 0 || takeBandages == 1) && (bandages >= 0 && bandages <= 30) && (takeMarbles == 0 || takeMarbles == 1)
            && (marbles >= 0 && marbles <= 100) && (takeRope == 0 || takeRope == 1) && (ropeM >= 0 && ropeM <= 60) &&
            (packKg >= 0 && packKg <= 150) && (stamina >= 0 && stamina <= 100) && (playersLeft >= 2 && playersLeft <= 456)
            && (bet == 0 || bet == 1 || bet == 2) && (stake >= 0 && stake <= 2000) && (favor == 0 || favor == 1 || favor == 2 || favor == 3)
            && (cash >= 0 && cash <= 6000) && (debt >= 0 && debt <= 3000) && (card == 0 || card == 1) && (ally == 0 || ally == 1))
            ?

            //item cost
            (type == 65) ? ropePrice = 100 : ropePrice = 120,
            (type == 84) ? needlePrice = 120 : needlePrice = 150,
            (type == 71) ? marblePrice = 45 : marblePrice = 60,

            //needle cost calculation
            (takeNeedles == 1 && needles > 10) ? dneedles = needles - 10 : dneedles = 0,
            (takeNeedles == 1 && needles > 10) ? dneedlePrice = needlePrice*75/100 : dneedlePrice = 0,
            (takeNeedles == 1 && needles > 10) ? dneedleCost = dneedles * dneedlePrice : dneedleCost = 0, 
            (takeNeedles == 1 && needles > 10) ? ftneedleCost = 10 * needlePrice : ftneedleCost = 0,
            (takeNeedles == 1 && needles > 10) ? needleCost = dneedleCost + ftneedleCost : needleCost = needles * needlePrice,

            //marbles cost calculation
            (takeMarbles == 1 && marbles > 50) ? dmarbles = marbles - 50 : dmarbles = 0,
            (takeMarbles == 1 && marbles > 50) ? dmarblePrice = marblePrice*50/100 : dmarblePrice = 0,
            (takeMarbles == 1 && marbles > 50) ? dmarbleCost = dmarbles * dmarblePrice : dmarbleCost = 0,
            (takeMarbles == 1 && marbles > 50) ? ffmarbleCost = 50 * marblePrice : ffmarbleCost = 0,
            (takeMarbles == 1 && marbles > 50) ? marbleCost = dmarbleCost + ffmarbleCost : marbleCost = marbles * marblePrice,

            //bandages cost calculation
            dbandages = bandages - (bandages/3),
            bandageCost = dbandages * bandagePrice,

            //rope cost calculation
            ropeCost = ropeM * ropePrice,

            //alert adjustment
            alertAdj = guardAlert,
            (takeMarbles == 1) ? alertAdj += marbles/5 : alertAdj = alertAdj,
            (takeRope == 1) ? alertAdj += ropeM/3 : alertAdj = alertAdj,
            (lightsOn == 1) ? alertAdj += 10 : alertAdj = alertAdj,
            (cameras == 1) ? alertAdj += 5 : alertAdj = alertAdj,

            //clamp
            (alertAdj > 100) ? alertAdj = 100 : alertAdj = alertAdj,

            //danger points

            (playersLeft > 300) ? Crowd = 3 : (playersLeft > 150) ? Crowd = 2 : (playersLeft > 50) ? Crowd = 1 : Crowd = 0,
            (alertAdj >= 70) ? Alert = 2 : (alertAdj >= 40) ? Alert = 1 : Alert = 0,
            (game >= 4) ? Game = 2 : (game >= 2) ? Game = 1 : Game = 0,
            (cameras == 1) ? Cameras += 1 : Cameras += 0,
            (lightsOn == 0) ? Darkness -= 1 : Darkness -= 0,

            TotalDangerPoints = Crowd + Alert + Cameras + Darkness + Game,

            (TotalDangerPoints < 0) ? TotalDangerPoints = 0 : TotalDangerPoints = TotalDangerPoints,

            //Surcharge
            (TotalDangerPoints >= 7) ? surchargePct = 50 : (TotalDangerPoints >= 5) ? surchargePct = 25 : (TotalDangerPoints >= 3) ? surchargePct = 10 : surchargePct = 0,

            NeedleS = (needleCost * (100 + surchargePct))/100,
            MarblesS = (marbleCost * (100 + surchargePct))/100,
            BandagesS = (bandageCost * (100 + surchargePct))/100,
            RopeS = (ropeCost * (100 + surchargePct))/100,

            itemsAfterSurcharge = NeedleS + MarblesS + BandagesS + RopeS,

            //Fees

            (timeLeft < 15) ? lateFee = 250 : (timeLeft < 45) ? lateFee = 100 : lateFee = 0,
            GuardToll = 50 + (alertAdj / 10) * 5,
            (card == 1 && cameras == 0) ? GuardToll = 0 : GuardToll = GuardToll,
            
            (type == 65) ? carryCap = 40 : (type == 84) ? carryCap = 30 : carryCap = 35,
            (ally == 1) ? carryCap += 10 : carryCap = carryCap,
            
            weightPenalty = min(500, 25 * max(0, packKg - carryCap)),

            (bet != 0) ? wager = stake : wager = 0,

            //Rebates and Ingury Tax

            (ally == 1) ? allyRebate = 60 : allyRebate = 0,
            (inguries == 0 && stamina >= 70) ? calmRebate = 40 : calmRebate = 0,
            (inguries == 0) ? injuryTax = 0 : (inguries == 1) ? injuryTax = 30 : (inguries == 2) ? injuryTax = 90 : injuryTax = 200,

            //favors

            (favor == 0) ? favorDiscount = 0 : favorDiscount = 0,

            (favor == 1 && (game == 2 || game == 4)) ? favorDiscount = (NeedleS + MarblesS) * 15/100 : favorDiscount = favorDiscount,
            (favor == 1 && favorDiscount > 500) ? favorDiscount = 500 : favorDiscount = favorDiscount,

            (favor == 2 && alertAdj >= 60) ? favorDiscount = (lateFee + GuardToll) * 50/100 : favorDiscount = favorDiscount,
            (favor == 2 && favorDiscount > 250) ? favorDiscount = 250 : favorDiscount = favorDiscount,

            (favor == 3 && inguries >= 1) ? favorDiscount = (BandagesS)*35/100 : favorDiscount = favorDiscount,
            (favor == 3 && favorDiscount > 900) ? favorDiscount = 900 : favorDiscount = favorDiscount,


            //settlement

            gross = itemsAfterSurcharge + lateFee + GuardToll + weightPenalty + wager,
            net = max(0, gross + injuryTax - allyRebate - calmRebate - favorDiscount),
            (net > cash) ? debtFee = 80 + debt/20.0 : debtFee = 0,
            Total = net + debtFee,
            (Total < 200) ? Total = 200 : Total = Total,
            fees = lateFee + GuardToll + weightPenalty + injuryTax + debtFee,
            cashUsed = min(cash, Total),
            payable = Total - cashUsed,

            //survival
            (takeRope == 1) ? survivalChance += min(15, ropeM/2) : survivalChance = survivalChance,
            (takeBandages == 1) ? survivalChance += min(12, bandages*2) : survivalChance = survivalChance,
            survivalChance += stamina/4,
            (card == 1) ? survivalChance += 8 : survivalChance -= 25,
            (ally == 1) ? survivalChance += 5 : survivalChance = survivalChance,
            survivalChance -= max(0, packKg - carryCap) / 2,
            survivalChance -= 5 * (surchargePct / 10),
            survivalChance -= 8 * inguries,
            survivalChance -= 4 * (game - 1),
            (debtFee > 0) ? survivalChance -= 12 : survivalChance = survivalChance,

            (game == 2 && (takeNeedles == 1 && needles >= 5)) ? survivalChance += 10 : survivalChance = survivalChance,
            (game == 4 && (takeMarbles == 1 && marbles >= 20)) ? survivalChance += 10 : survivalChance = survivalChance,
            (game == 5 && (takeRope == 1 && ropeM >= 10)) ? survivalChance += 10: survivalChance = survivalChance,

            (survivalChance < 0) ? survivalChance = 0 : survivalChance = survivalChance,
            (survivalChance > 100) ? survivalChance = 100 : survivalChance = survivalChance,

            (survivalChance >= 55) ? outcome = 1 : outcome = 0,

            //Prize and Final Prize

            prizePool = (456 - playersLeft) * 100,
            (outcome == 1) ? prizeShare = prizePool/playersLeft : prizeShare = 0,

            (outcome == 1 && bet == 1) ? betPayout = (stake * 3) / 2 : betPayout = 0,
            (outcome == 1 && bet == 0) ? betPayout = 0 : betPayout = 0,
            (outcome == 1 && bet == 2 && survivalChance >= 75) ? betPayout = stake * 4 : betPayout = 0,

            //final balance
            finalBalance = cash - Total + prizeShare + betPayout,

            cout<<"================"<<endl,
            cout<<"    Output!"<<endl,
            cout<<"================"<<endl,
            cout<<"Needle Cost: "<<needleCost<<endl,
            cout<<"Bandage Cost: "<<bandageCost<<endl,
            cout<<"Marble Cost: "<<marbleCost<<endl,
            cout<<"Rope Cost: "<<ropeCost<<endl,

            cout<<"Danger Points: "<<TotalDangerPoints<<endl,
            cout<<"Surcharge Pct: "<<surchargePct<<"%"<<endl,
            cout<<"Late Fee: "<<lateFee<<endl,
            cout<<"Guard Toll: "<<GuardToll<<endl,
            cout<<"Weight Penalty: "<<weightPenalty<<endl,
            
            cout<<"Wager: "<<wager<<endl,
            cout<<"Favor Discount: "<<favorDiscount<<endl,
            cout<<"Fees: "<<fees<<endl,
            cout<<"Total: "<<Total<<endl,
            cout<<"Cash Used: "<<cashUsed<<endl,
            cout<<"Payable: "<<payable<<endl,
            cout<<"Survival Chance: "<<survivalChance<<endl,

            cout<<"Outcome: "<<outcome<<endl,
            cout<<"Prize Share: "<<prizeShare<<endl,
            cout<<"Bet Payout: "<<betPayout<<endl,
            cout<<"Final Balnance: "<<finalBalance<<endl : cout<<"Invalid Input! Program Crashed";

            break;

        }
        case 2:
        {
            //Part A

            double V, U, thetaS, D, C1, C2, C3, C4;
            double Wnot = 0.8, beta = 0.12, Unot = 15.0, mu = 3.4, Dnot = 0.5;
            int rollLast4;

            cout<<"Enter a wind speed: ";
            cin>>U;

            cout<<"Terrain Slope Angle in radians: ";
            cin>>thetaS;

            cout<<"Vegetation Fuel Index: ";
            cin>>D;

            cout<<"Enter last 4 digit of roll no: ";
            cin>>rollLast4;

            C1 = Wnot * (exp(beta*U));
            C2 = Unot * pow(sin(thetaS), 2);
            C3 = mu * log( (D + 1.0)/  Dnot);
            C4 = sqrt(U * cos(thetaS) + 1.0);

            V = C1 + C2 + C3 + C4;

            cout << fixed << setprecision(4) << "Velocity: " << V <<endl;

            //Part B
            int V_int = V;
            int Final = (V * 10000),f1 = 0, f2 = 0;
            int R, K;

            //digit 1, 2, 3 and 4
            f2 = Final % 100;
            Final = Final / 100;

            f1 = Final % 100;

            //R
            R = ((rollLast4) % 89) + 10;

            K = (V_int * pow(10, 6)) + (f1 * pow(10, 4)) + (f2 * pow(10, 2)) + R;
            cout<<"K: "<<K<<endl;


            //Part c
            int tempR, R1, R2, penalty, threat;
            char ch1, ch2;
            bool is_exact = 0;

            float v_float;
            float Uf = U, thetaSf = thetaS, Df = D, C1f, C2f, C3f, C4f;
            float Wnotf = 0.8, betaf = 0.12, Unotf = 15.0, muf = 3.4, Dnotf = 0.5;

            double v_double;
            double Ud = U, thetaSd = thetaS, Dd = D, C1d, C2d, C3d, C4d;
            double Wnotd = 0.8, betad = 0.12, Unotd = 15.0, mud = 3.4, Dnotd = 0.5;

            tempR = K % 100;

            R1 = V_int % 26;
            ch1 = R1 + 'A';

            R2 = tempR % 26;
            ch2 = 'Z' - R2;
            
            cout<<"Status Tag: "<<ch1<<ch2<<endl;

            //V_float
            C1f = Wnotf * (exp(betaf*Uf));
            C2f = Unotf * pow(sin(thetaSf), 2);
            C3f = muf * log( (Df + 1.0)/  Dnotf);
            C4f = sqrt(Uf * cos(thetaSf) + 1.0);

            v_float = C1f + C2f + C3f + C4f;

            //V_Double
            C1d = Wnotd * (exp(betad*Ud));
            C2d = Unotd * pow(sin(thetaSd), 2);
            C3d = mud * log( (Dd + 1.0)/  Dnotd);
            C4d = sqrt(Ud * cos(thetaSd) + 1.0);

            v_double = C1d + C2d + C3d + C4d;

            //Precision Flag
            is_exact = (v_float == v_double);
            cout<<"Precision Match Flag: "<<is_exact<<endl;

            //Penalty
            penalty = 25 * (!is_exact);
            threat = tempR + penalty + (1.5 * v_double);

            cout<<"Threat Rating: "<<threat<<endl;
            break;
        }
        case 3:
        {
            //Murdoach
            int murvisitedBoilerRoom = 1, murvisitedCargoHold = 0, murvisitedThirdClass = 0, murvisitedDiningSalon = 0;
            int murvisitedPromenadeDeck = 0, murvisitedBridge = 0, murvisitedLifeBoatDeck = 0, murvisitedCrowsNest = 0;

            //Marry
            int marryvisitedBoilerRoom = 1, marryvisitedCargoHold = 0, marryvisitedThirdClass = 0, marryvisitedDiningSalon = 0;
            int marryvisitedPromenadeDeck = 0, marryvistedBridge = 0, marryvisitedLifeBoatDeck = 0, marryvisitedCrowsNest = 0;

            int murCurrent = 0, marryCurrent = 0, murstop = 0, marrystop = 0, murForcedMove = 0, marryForcedMove = 0;
            
            //Murdoach Move 1

            cout<<"Murdoch Path: Boiler Room";
            switch(murstop)
            {
                case 1:
                    break;
                case 0:
                murForcedMove = 0;
                    switch(murCurrent)
                    {
                        //flooding rule 1
                        case 2:
                            switch(murvisitedBridge){
                                case 0:
                                    cout<<" Water Rising";
                                    murCurrent = 5;
                                    murForcedMove = 1;
                                    murvisitedBridge = 1;
                                    break;
                                case 1:
                                    break;
                            }
                        break;
                    }
                    switch(murForcedMove){
                        case 1:
                            break;
                        case 0:
                            switch(murCurrent){
                                case 0:
                                    switch(murvisitedCargoHold){
                                        case 0:
                                            murvisitedCargoHold = 1;
                                            murCurrent = 1;
                                            break;
                                        case 1:
                                            switch(murvisitedThirdClass){
                                                case 0:
                                                    murvisitedThirdClass = 1;
                                                    murCurrent = 2;
                                                    break;
                                                case 1:
                                                    cout<<"Turn Back";
                                                    //first we check deck 1 -> 3, 4
                                                    switch(murvisitedDiningSalon){
                                                        case 0:
                                                            murCurrent = 1;
                                                            break;
                                                        case 1:
                                                            switch(murvisitedPromenadeDeck){
                                                                case 0:
                                                                    murCurrent = 1;
                                                                    break;
                                                                case 1:
                                                                    //becuase 3 and 4 visited
                                                                    switch(murvisitedBridge){
                                                                        case 0:
                                                                            murCurrent = 2;
                                                                            break;
                                                                        case 1:
                                                                            switch(murvisitedLifeBoatDeck){
                                                                                case 0:
                                                                                    murCurrent = 2;
                                                                                    break;
                                                                                case 1:
                                                                                    cout<<"Trapped";
                                                                                    break;
                                                                            }
                                                                        break;
                                                                    }
                                                                break;
                                                            }
                                                        break;
                                                    }
                                                break;
                                            }
                                        break;
                                    }
                                break;
                            }
                        break;
                    }
                    switch(murCurrent){
                        case 6:
                            cout<<" Rescued!";
                            murstop = 1;
                            break;
                    }
                    switch(murCurrent){
                        case 7:
                            switch(murvisitedDiningSalon){
                                case 1:
                                    cout<<" Door Sealed!";
                                    murvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                break;
            }
            
            switch (murCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }
            
            //Murdoch Move 2

            switch (murstop)
            {
                case 0:
                    murForcedMove = 0;

                    switch (murCurrent)
                    {
                        case 2:
                            switch (murvisitedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    murCurrent = 5;
                                    murvisitedBridge = 1;
                                    murForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (murForcedMove)
                    {
                        case 0:
                            switch (murCurrent)
                            {
                                case 1:
                                    switch (murvisitedDiningSalon)
                                    {
                                        case 0:
                                            murCurrent = 3;
                                            murvisitedDiningSalon = 1;
                                            break;
                                        case 1:
                                            switch (murvisitedPromenadeDeck)
                                            {
                                                case 0:
                                                    murCurrent = 4;
                                                    murvisitedPromenadeDeck = 1;
                                                    break;
                                                case 1:
                                                    cout << " TurnBack";
                                                    murCurrent = 0;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            murstop = 1;
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 7:
                            switch (murvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    murvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (murCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            //Murdoch Move 3
            switch (murstop)
            {
                case 0:
                    murForcedMove = 0;

                    switch (murCurrent)
                    {
                        case 2:
                            switch (murvisitedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    murCurrent = 5;
                                    murvisitedBridge = 1;
                                    murForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (murForcedMove)
                    {
                        case 0:
                            switch (murCurrent)
                            {
                                case 3:
                                    switch (murvisitedCrowsNest)
                                    {
                                        case 0:
                                            murCurrent = 7;
                                            murvisitedCrowsNest = 1;
                                            break;
                                        case 1:
                                            cout<<" Turn Back";
                                            murCurrent = 1;
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            murstop = 1;
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 7:
                            switch (murvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    murvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (murCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }
            
            //Murdoch Move 4
            switch (murstop)
            {
                case 0:
                    murForcedMove = 0;

                    switch (murCurrent)
                    {
                        case 2:
                            switch (murvisitedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    murCurrent = 5;
                                    murvisitedBridge = 1;
                                    murForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (murForcedMove)
                    {
                        case 0:
                            switch (murCurrent)
                            {
                                case 7:
                                    switch (murvisitedDiningSalon)
                                    {
                                        case 0:
                                            murCurrent = 3;
                                            murvisitedDiningSalon = 1;
                                            break;
                                        case 1:
                                            switch(murvisitedPromenadeDeck){
                                                case 0:
                                                    murCurrent = 4;
                                                    murvisitedPromenadeDeck = 1;
                                                    break;
                                                case 1:
                                                    cout<<"Turn Back";
                                                    murCurrent = 1;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            murstop = 1;
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 7:
                            switch (murvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    murvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (murCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            //Murdoch Move 5
            switch (murstop)
            {
                case 0:
                    murForcedMove = 0;

                    switch (murCurrent)
                    {
                        case 2:
                            switch (murvisitedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    murCurrent = 5;
                                    murvisitedBridge = 1;
                                    murForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (murForcedMove)
                    {
                        case 0:
                            switch (murCurrent)
                            {
                                case 3:
                                    switch (murvisitedCargoHold)
                                    {
                                        case 1:
                                            switch (murvisitedCrowsNest)
                                            {
                                                case 1:
                                                    cout << " TurnBack";
                                                    murCurrent = 1;
                                                    break;
                                                case 0:
                                                    murCurrent = 7;
                                                    murvisitedCrowsNest = 1;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            murstop = 1;
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 7:
                            switch (murvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    murvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (murCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            //Murdoch move 6
            switch (murstop)
            {
                case 0:
                    murstop = 0;

                    switch (murCurrent)
                    {
                        case 2:
                            switch (murvisitedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    murCurrent = 5;
                                    murvisitedBridge = 1;
                                    murForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (murForcedMove)
                    {
                        case 0:
                            switch (murCurrent)
                            {
                                case 1:
                                    switch (murvisitedPromenadeDeck)
                                    {
                                        case 0:
                                            murCurrent = 4;
                                            murvisitedPromenadeDeck = 1;
                                            break;
                                        case 1:
                                            cout << " Trapped";
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            murstop = 1;
                            break;
                    }

                    switch (murCurrent)
                    {
                        case 7:
                            switch (murvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    murvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (murCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            cout << endl;


            //Marry Move 1

            cout<<"Marry Path: Boiler Room";
            switch (marrystop)
            {
                case 0:
                    marryForcedMove = 0;

                    switch (marryCurrent)
                    {
                        case 2:
                            switch (marryvistedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    marryCurrent = 5;
                                    marryvistedBridge = 1;
                                    marryForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (marryForcedMove)
                    {
                        case 0:
                            switch (marryCurrent)
                            {
                                case 0:
                                    switch (marryvisitedCargoHold)
                                    {
                                        case 0:
                                            marryCurrent = 1;
                                            marryvisitedCargoHold = 1;
                                            break;
                                        case 1:
                                            switch (marryvisitedThirdClass)
                                            {
                                                case 0:
                                                    marryCurrent = 2;
                                                    marryvisitedThirdClass = 1;
                                                    break;
                                                case 1:
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            marrystop = 1;
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 7:
                            switch (marryvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    marryvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (marryCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            //Marry Move 2
            switch (marrystop)
            {
                case 0:
                    marryForcedMove = 0;

                    switch (marryCurrent)
                    {
                        case 2:
                            switch (marryvistedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    marryCurrent = 5;
                                    marryvistedBridge = 1;
                                    marryForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (marryForcedMove)
                    {
                        case 0:
                            switch (marryCurrent)
                            {
                                case 1:
                                    switch (marryvisitedThirdClass)
                                    {
                                        case 0:
                                            marryCurrent = 0;
                                            break;
                                        case 1:
                                            switch (marryvisitedDiningSalon)
                                            {
                                                case 0:
                                                    marryCurrent = 3;
                                                    marryvisitedDiningSalon = 1;
                                                    break;
                                                case 1:
                                                    switch (marryvisitedPromenadeDeck)
                                                    {
                                                        case 0:
                                                            marryCurrent = 4;
                                                            marryvisitedPromenadeDeck = 1;
                                                            break;
                                                        case 1:
                                                            break;
                                                    }
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            marrystop = 1;
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 7:
                            switch (marryvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    marryvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (marryCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            //marry move 3
            switch (marrystop)
            {
                case 0:
                    marryForcedMove = 0;

                    switch (marryCurrent)
                    {
                        case 2:
                            switch (marryvistedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    marryCurrent = 5;
                                    marryvistedBridge = 1;
                                    marryForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (marryForcedMove)
                    {
                        case 0:
                            switch (marryCurrent)
                            {
                                case 0:
                                    switch (marryvisitedThirdClass)
                                    {
                                        case 0:
                                            marryCurrent = 2;
                                            marryvisitedThirdClass = 1;
                                            break;
                                        case 1:
                                            switch (marryvisitedCargoHold)
                                            {
                                                case 0:
                                                    marryCurrent = 1;
                                                    marryvisitedCargoHold = 1;
                                                    break;
                                                case 1:
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            marrystop = 1;
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 7:
                            switch (marryvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    marryvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (marryCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            //Marry move 4
            switch (marrystop)
            {
                case 0:
                    marryForcedMove = 0;

                    switch (marryCurrent)
                    {
                        case 2:
                            switch (marryvistedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    marryCurrent = 5;
                                    marryvistedBridge = 1;
                                    marryForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (marryForcedMove)
                    {
                        case 0:
                            switch (marryCurrent)
                            {
                                case 2:
                                    switch (marryvisitedLifeBoatDeck)
                                    {
                                        case 0:
                                            marryCurrent = 6;
                                            marryvisitedLifeBoatDeck = 1;
                                            break;
                                        case 1:
                                            switch (marryvistedBridge)
                                            {
                                                case 0:
                                                    marryCurrent = 5;
                                                    marryvistedBridge = 1;
                                                    break;
                                                case 1:
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            marrystop = 1;
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 7:
                            switch (marryvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    marryvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (marryCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            //Marry move 5

            switch (marrystop)
            {
                case 0:
                    marryForcedMove = 0;

                    switch (marryCurrent)
                    {
                        case 2:
                            switch (marryvistedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    marryCurrent = 5;
                                    marryvistedBridge = 1;
                                    marryForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (marryForcedMove)
                    {
                        case 0:
                            switch (marryCurrent)
                            {
                                case 5:
                                    switch (marryvisitedLifeBoatDeck)
                                    {
                                        case 0:
                                            marryCurrent = 6;
                                            marryvisitedLifeBoatDeck = 1;
                                            break;
                                        case 1:
                                            switch (marryvisitedCrowsNest)
                                            {
                                                case 0:
                                                    marryCurrent = 7;
                                                    marryvisitedCrowsNest = 1;
                                                    break;
                                                case 1:
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            marrystop = 1;
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 7:
                            switch (marryvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    marryvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (marryCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            //Murdock Move 6
            switch (marrystop)
            {
                case 0:
                    marryForcedMove = 0;

                    switch (marryCurrent)
                    {
                        case 2:
                            switch (marryvistedBridge)
                            {
                                case 0:
                                    cout << " WaterRising";
                                    marryCurrent = 5;
                                    marryvistedBridge = 1;
                                    marryForcedMove = 1;
                                    break;
                                case 1:
                                    break;
                            }
                            break;
                    }

                    switch (marryForcedMove)
                    {
                        case 0:
                            switch (marryCurrent)
                            {
                                case 5:
                                    switch (marryvisitedLifeBoatDeck)
                                    {
                                        case 0:
                                            marryCurrent = 6;
                                            marryvisitedLifeBoatDeck = 1;
                                            break;
                                        case 1:
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 6:
                            cout << " Rescued";
                            marrystop = 1;
                            break;
                    }

                    switch (marryCurrent)
                    {
                        case 7:
                            switch (marryvisitedDiningSalon)
                            {
                                case 1:
                                    cout << " DoorSealed";
                                    marryvisitedDiningSalon = 0;
                                    break;
                            }
                            break;
                    }
                    break;
                case 1:
                    break;
            }

            switch (marryCurrent)
            {
                case 0: cout << " -> Boiler Room"; break;
                case 1: cout << " -> Cargo Hold"; break;
                case 2: cout << " -> Third Class"; break;
                case 3: cout << " -> Dining Saloon"; break;
                case 4: cout << " -> Promenade Deck"; break;
                case 5: cout << " -> Bridge"; break;
                case 6: cout << " -> Lifeboat Deck"; break;
                case 7: cout << " -> Crow's Nest"; break;
            }

            cout << '\n';
                    break;
        }
        case 4:
        {
            int n;
            cout<<"Enter a number: ";
            cin>>n;

            int mid = n/2 + 1;

            
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == n || i == 1 || j == 1 || j == n)
                    {
                        cout<<"*";
                    }
                    
                    else if (i == mid || j == mid)
                    {
                        if ((n/2) % 2 == 0)
                        {
                            cout<<"*";
                        }
                        else{
                            cout<<" ";
                        }
                        
                    }

                    //first quadrant
                    else if (i < mid && j < mid && (i % 2 != 0 && j <= i))
                    {
                        cout<<"*";
                    }

                    else if (i < mid && j < mid && (i % 2 == 0 || i%2 != 0) && j % 2 != 0 && j > i)
                    {
                        cout<<"*";
                    }
                    
                    //second quadrant
                    else if (j > mid && i < mid && (i % 2 != 0 && i + j >= n + 1))
                    {
                        cout<<"*";
                    }
                    
                    else if(j > mid && i < mid && (i % 2 == 0 || i%2 != 0) && (j % 2 != 0 && n - j >= i)){
                        cout<<"*";
                    }

                    //third quadrant
                    else if (j < mid && i > mid && (i %2 != 0 && i + j <= n+1))
                    {
                        cout<<"*";
                    }

                    else if (j < mid && i > mid && (i % 2 == 0 || i % 2 != 0) && (j % 2 != 0) && (i + j >= n+1))
                    {
                        cout<<"*";
                    }
                    
                    //fourth quadrant
                    else if (i > mid && j > mid && (i %2 != 0 && j >= i))
                    {
                        cout<<"*";
                    }
                    
                    else if (i > mid && j > mid && (i %2 == 0 || i %2 != 0) && (j %2 != 0) && (i > j))
                    {
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }    
                }
                cout<<endl;   
            }
            break;
        }    
        case 5:
        {
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            break;
        }    
        case 8:
        {
            int H = 10, W = 20;

            int pacManX, pacManY;
            int blinkyX, blinkyY;
            int pinkyX, pinkyY;
            int clydeX, clydeY;
            int inkyX, inkyY;
            
            int inkyD, pinkyD, clydeD, blinkyD;

            char direction;
            bool flag = true;

            pacManX = rand() % 20;
            pacManY = rand() % 10;

            blinkyX = rand() % 20;
            blinkyY = 3;

            pinkyX = rand() % 20;
            pinkyY = rand() % 10;

            clydeX = rand() % 20;
            clydeY = rand() % 10;

            inkyX = rand() % 20;
            inkyY = rand() % 10;

            cout << "Pac-Man: " << pacManX << ", " << pacManY << endl;
            cout << "Blinky: " << blinkyX << ", " << blinkyY << endl;
            cout << "Pinky: " << pinkyX << ", " << pinkyY << endl;
            cout << "Clyde: " << clydeX << ", " << clydeY << endl;
            cout << "Inky: " << inkyX << ", " << inkyY << endl;
            
            // cout<<endl<<endl;

            while(flag){
                cout<<"Please Enter Direction For PacMan: ";
                cin>>direction;

                //PacMan
                switch(direction){
                    case 'W':
                        pacManY += 1;
                        (pacManY > 9) ? pacManY = 0 : pacManY = pacManY;

                        clydeY += 1;
                        (clydeY > 9) ? clydeY = 9 : clydeY = clydeY;
                        break;
                    case 'A':
                        pacManX -= 1;
                        (pacManX < 0) ? pacManX = 19 : pacManX = pacManX;

                        clydeX -= 1;
                        (clydeX < 0) ? clydeX = 0 : clydeX = clydeX;
                        break;
                    case 'S': 
                        pacManY -= 1;
                        (pacManY < 0) ? pacManY = 9 : pacManY = pacManY;

                        clydeY -= 1;
                        (clydeY < 0) ? clydeY = 0 : clydeY = clydeY;
                        break;
                    case 'D': 
                        pacManX += 1;
                        (pacManX > 19) ? pacManX = 0 : pacManX = pacManX;

                        clydeX += 1;
                        (clydeX > 19) ? clydeX = 19 : clydeX = clydeX;
                        break;
                }
                
                //Blinky
                (blinkyX > 19) ? blinkyX = 19, blinkyY = 6 : blinkyX = blinkyX, blinkyY = blinkyY;
                (blinkyX < 0) ? blinkyX = 0, blinkyY = 3 : blinkyX = blinkyX, blinkyY = blinkyY;
                (blinkyY == 3) ? blinkyX += 1 : blinkyX -= 1;

                //Pinky

                int horizontal = abs(pacManX - pinkyX);
                int vertical = abs(pacManY - pinkyY);

                ((horizontal < vertical) && (pacManX > pinkyX)) ? pinkyX++ :
                ((horizontal < vertical) && (pacManX < pinkyX)) ? pinkyX-- : pinkyX;

                ((horizontal > vertical) && (pacManY > pinkyY)) ? pinkyY++ :
                ((horizontal > vertical) && (pacManY < pinkyY)) ? pinkyY-- : pinkyY;

                ((horizontal == vertical) && (pacManX > pinkyX)) ? pinkyX++ :
                ((horizontal == vertical) && (pacManX < pinkyX)) ? pinkyX-- : pinkyX;

                ((horizontal == vertical) && (pacManY > pinkyY)) ? pinkyY++ :
                ((horizontal == vertical) && (pacManY < pinkyY)) ? pinkyY-- : pinkyY; 


                //Inky

                //Distance
                bool inkyDis = false;

                blinkyD = sqrt(pow((blinkyX - pacManX), 2) + pow((blinkyY - pacManY), 2));
                pinkyD = sqrt(pow((pinkyX - pacManX), 2) + pow((pinkyY - pacManY), 2));
                clydeD = sqrt(pow((clydeX - pacManX), 2) + pow((clydeY - pacManY), 2));
                inkyD = sqrt(pow((inkyX - pacManX), 2) + pow((inkyY - pacManY), 2));

                ((inkyD < blinkyD) && (inkyD < pinkyD) && (inkyD < clydeD)) ? inkyDis = true: inkyDis = false;

                (inkyDis == true) ?
                (
                    //(pacManX, pacManY-1)
                    (((pacManX == blinkyX) && (pacManY-1 == blinkyY)) ||
                    ((pacManX == pinkyX) && (pacManY-1 == pinkyY)) ||
                    ((pacManX == clydeX) && (pacManY-1 == clydeY))) ?

                    //(pacManX+1, pacManY-1)
                    ((((pacManX+1 == blinkyX) && (pacManY-1 == blinkyY)) ||
                    ((pacManX+1 == pinkyX) && (pacManY-1 == pinkyY)) ||
                    ((pacManX+1 == clydeX) && (pacManY-1 == clydeY))) ?

                    //(pacManX+1, pacManY)
                    ((((pacManX+1 == blinkyX) && (pacManY == blinkyY)) ||
                    ((pacManX+1 == pinkyX) && (pacManY == pinkyY)) ||
                    ((pacManX+1 == clydeX) && (pacManY == clydeY))) ?

                    //(pacManX+1, pacManY+1)
                    ((((pacManX+1 == blinkyX) && (pacManY+1 == blinkyY)) ||
                    ((pacManX+1 == pinkyX) && (pacManY+1 == pinkyY)) ||
                    ((pacManX+1 == clydeX) && (pacManY+1 == clydeY))) ?

                    //(pacManX, pacManY+1)
                    ((((pacManX == blinkyX) && (pacManY+1 == blinkyY)) ||
                    ((pacManX == pinkyX) && (pacManY+1 == pinkyY)) ||
                    ((pacManX == clydeX) && (pacManY+1 == clydeY))) ?

                    //(pacManX-1, pacManY+1)
                    ((((pacManX-1 == blinkyX) && (pacManY+1 == blinkyY)) ||
                    ((pacManX-1 == pinkyX) && (pacManY+1 == pinkyY)) ||
                    ((pacManX-1 == clydeX) && (pacManY+1 == clydeY))) ?

                    //(pacManX-1, pacManY)
                    ((((pacManX-1 == blinkyX) && (pacManY == blinkyY)) ||
                    ((pacManX-1 == pinkyX) && (pacManY == pinkyY)) ||
                    ((pacManX-1 == clydeX) && (pacManY == clydeY))) ?

                    //(pacManX-1, pacManY-1)
                    ((((pacManX-1 == blinkyX) && (pacManY-1 == blinkyY)) ||
                    ((pacManX-1 == pinkyX) && (pacManY-1 == pinkyY)) ||
                    ((pacManX-1 == clydeX) && (pacManY-1 == clydeY))) ?

                    // All eight cells occupied
                    (inkyX = inkyX, inkyY = inkyY) :

                    (inkyX = pacManX-1, inkyY = pacManY-1)) :

                    (inkyX = pacManX-1, inkyY = pacManY)) :

                    (inkyX = pacManX-1, inkyY = pacManY+1)) :

                    (inkyX = pacManX, inkyY = pacManY+1)) :

                    (inkyX = pacManX+1, inkyY = pacManY+1)) :

                    (inkyX = pacManX+1, inkyY = pacManY)) :

                    (inkyX = pacManX+1, inkyY = pacManY-1)) :

                    (inkyX = pacManX, inkyY = pacManY-1)) :

                    (inkyX = inkyX, inkyY = inkyY);

                    //Win
                ((pacManX == clydeX) && (pacManY == clydeY)) ? flag = false
                : ((pacManX == blinkyX) && (pacManY == blinkyY) || (pacManX == pinkyX) && (pacManY == pinkyY)
                || (pacManX == inkyX) && (pacManY == inkyY)) ? flag = false : flag = true;

                ((pacManX == clydeX) && (pacManY == clydeY)) ? cout << "Pac-Man Win" : cout<<"";
                (((pacManX == blinkyX) && (pacManY == blinkyY)) || ((pacManX == pinkyX) && (pacManY == pinkyY))
                || ((pacManX == inkyX) && (pacManY == inkyY))) ? cout << "Pac-Man lose"<<endl : cout<<"";

                for (int i = 0; i < H; i++)
                {
                    for (int j = 0; j < W; j++)
                    {
                        //Printing
                        (i == pacManY && j == pacManX) ? cout<<"@" : (i == blinkyY && j == blinkyX) ? cout<<"B" :
                        (i == pinkyY && j == pinkyX) ? cout<<"P" : (i == clydeY && j == clydeX) ? cout<<"C" :
                        (i == inkyY && j == inkyX) ? cout<<"I" : cout<<"*";       
                    }
                    cout<<endl;
                }
            }
            break;
        }    
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}