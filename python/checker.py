def check(route):
    # check the route
    # print("input route: ", route)

    # route feasibility
    if len(route) % 2 == 0:
        return True

    else:
        return False
