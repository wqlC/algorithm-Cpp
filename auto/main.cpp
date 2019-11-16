#include <iostream>
enum GameResult {WIN, LOSE, TIE, CANCEL};

int main(){
    GameResult result;
    enum GameResult omit = CANCEL;
    int val1 = 2;
    int val2 = 3;
    auto val = val1 + val2;
    decltype(result) j = WIN;
    for(int count = WIN; count<= CANCEL; count++){
        result = static_cast<GameResult> (count);
        if(result == omit){
            std::cout << "The game was cancelled" << std::endl;
        }
        else{
            std::cout << "The game was played ";
            if(result == WIN){
                std::cout << "and we won!";
            }
            if(result == LOSE){
                std::cout <<"and we lose.";
            }
            std::cout << std::endl;
        }
    }
    return 0;

}
