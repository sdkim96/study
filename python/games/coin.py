import enum
import time
import random
import uuid

class CoinStatus(enum.Enum):
    HEAD = 0
    TAIL = 1
    TOSSED = 2


class Coin:
    def __init__(self, coin_id: uuid.UUID = uuid.uuid4()):
        self.coin_id = coin_id
        self.current_status: CoinStatus = CoinStatus.HEAD

    def tossed(self) -> CoinStatus:
        self.current_status = CoinStatus.TOSSED
        print(f'{self.coin_id} 동전이 던져집니다.')
        time.sleep(2)
        print('결과는...')
        
        return self._toss_result()

    def _toss_result(self) -> CoinStatus:
        result = random.choice([CoinStatus.HEAD, CoinStatus.TAIL])
        self.current_status = result
        return result
        


class Player:
    def __init__(self, name: str):
        self.name = name
        self.coin_expecting: dict[uuid.UUID, CoinStatus] = {}  # 여러 동전 관리
    
    def toss(self, coin: Coin):
        print(f'{self.name}이 동전을 던집니다.')
        coin_result = coin.tossed()

        if coin_result == CoinStatus.HEAD:
            print(f'{coin.coin_id}는 앞면입니다!')
        else:
            print(f'{coin.coin_id}는 뒷면입니다!')

        if coin.coin_id in self.coin_expecting:
            if self.coin_expecting[coin.coin_id] == coin_result:
                print(f'{self.name}님, 정답입니다!')
            else:
                print(f'{self.name}님, 틀렸습니다!')
        else:
            print(f'{self.name}님, 예측하지 않은 동전입니다.')
    
    def expect(self, coin: Coin):
        while True:
            print(f'{self.name}이 동전({coin.coin_id})의 결과를 예측합니다!')
            expecting = input(f'{self.name}님, 예측할 결과를 입력하세요(앞면: 0, 뒷면: 1): ')
            if expecting in ["0", "1"]:
                self.coin_expecting[coin.coin_id] = CoinStatus(int(expecting))
                print(f'{self.name}님이 예측을 완료했습니다.')
                break
            else:
                print("잘못된 입력입니다. 0(앞면) 또는 1(뒷면)을 입력하세요.")


if __name__ == '__main__':
    coin = Coin()
    player1 = Player('철수')
    player2 = Player('영희')

    # 철수와 영희가 번갈아 가며 예측 및 동전 던지기
    player1.expect(coin)
    player2.expect(coin)

    player1.toss(coin)
    player2.toss(coin)