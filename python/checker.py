# import possible

# def check(route, chk):
#     c = possible.test_class(route)

#     if chk:
#         a = c.route
#         print("1", a)

#         if len(a) % 2 == 0:
#             a.append(0)
#             c.route = a

#     else:
#         print("false 종료")
#         return 0


def check(route):
    # cpp에서 받은 route 확인
    print("checker함수에서 route 받음", route)

    # route feasibility 연산
    if len(route) % 2 == 0:
        return True

    else:
        return False
