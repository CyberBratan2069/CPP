def weekdayGenerator():
    yield "Monday"
    yield "Tuesday"
    yield "Wednesday"
    yield "Thursday"
    yield "Friday"
    yield "Saturday"
    yield "Sunday"


def timesTwoGenerator(endValue):
    i = 1
    while i<=endValue:
        yield i * 2
        i += 1

for day in weekdayGenerator():
    print(day)

for j in timesTwoGenerator(5):
    print(j)
