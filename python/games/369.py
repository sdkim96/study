# 1단계 : 주어진 요구사항에 맞게 369 게임 구현
# 2단계 : 오답률에 따른 게임 종료 및 사용자 등 몇 가지 심화 기능과 클래스 추가
# 3단계 : 지역별 다른 규칙의 369 게임을 위해 추상화 및 다형성 적용
# 4단계 : 다양한 지역 동시 게임 진행을 위한 동시성 적용
# 출처: https://kang-james.tistory.com/entry/회고-라이브-코딩-면접-후기 [내 꿈을 JAVA:티스토리]

import abc
from typing import AsyncGenerator

class BaseGame369(abc.ABC):

    @abc.abstractmethod
    async def generate_num(self):
        ...

    @abc.abstractmethod
    async def game(self):
        ...


class SeoulGame369(BaseGame369):
    """
    서울은 3, 6, 9가 나오면 박수를 치는 게임
    """
    def __init__(self):
        super().__init__()

    async def generate_num(self, max_v: int):
        for i in range(1, max_v + 1):
            yield i

    async def game(self, gen: AsyncGenerator):
        
        async for n in gen:
            if n % 3 == 0:
                print('서울: 짝!')
                await asyncio.sleep(2)
            else:
                print('서울: ', n)
                


class BusanGame369(BaseGame369):
    """
    부산은 3, 6, 9가 나오면 박수를 치는 게임 + 5의 배수일 때 쿵을 치는 게임
    """
    def __init__(self):
        super().__init__()

    async def generate_num(self, max_v: int):
        for i in range(1, max_v + 1):
            yield i

    
    async def game(self, gen: AsyncGenerator):
        async for n in gen:
            if n % 3 == 0:
                print('부산: 짝!')
                await asyncio.sleep(1)
            elif n % 5 == 0:
                print('부산: 쿵!')
                await asyncio.sleep(4)
            else:
                print('부산: ', n)

class IncheonGame369(BaseGame369):
    """
    인천은 3, 6, 9가 나오면 박순데, 홀수만 generate하는 게임
    """
    def __init__(self):
        super().__init__()

    async def generate_num(self, max_v: int):
        for i in range(1, max_v + 1, 2):
            yield i

    
    async def game(self, gen: AsyncGenerator):
        async for n in gen:
            if n % 3 == 0:
                print('인천: 박순데')
                await asyncio.sleep(3)
            else:
                print('인천: ', n)

import asyncio

async def amain():

    incheon = IncheonGame369()
    seoul = SeoulGame369()
    busan = BusanGame369()
    games = [
        incheon.game(incheon.generate_num(20)), 
        seoul.game(seoul.generate_num(9)), 
        busan.game(busan.generate_num(10))
    ]

    print("게임 시작")
    await asyncio.gather(*games)

if __name__ == '__main__':

    asyncio.run(amain())