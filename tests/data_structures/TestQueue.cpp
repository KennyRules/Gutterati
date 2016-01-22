#include "../../include/catch.hpp"
#include "../../src/Queue.h"

SCENARIO( "A Queue can have items enqueued", "[Queue]") {

	GIVEN( "A empty queue") {
        Queue<int> aQueue;

		WHEN( "items are enqueued" ) {
            aQueue.enqueue(1);
            aQueue.enqueue(2);

			THEN( "the size increases" ) {
                REQUIRE(aQueue.getSize() == 2);
			}

			AND_THEN( "the elements exist" ) {
                REQUIRE(aQueue.peek() == 1);
                aQueue.dequeue();
                REQUIRE(aQueue.peek() == 2);
			}
		}

		AND_WHEN( "items are dequeued" ) {
            REQUIRE_THROWS_AS(aQueue.dequeue(), std::range_error);
            
            THEN( "the size remains 0" ) {
                REQUIRE(aQueue.getSize() == 0);
			}
		}
	}
}
SCENARIO( "A Queue can have items dequeued", "[Queue]") {

	GIVEN( "A queue with elements enqueued" ) {
        Queue<float> aQueue;
        aQueue.enqueue(3.14f);
        aQueue.enqueue(-5.3f);

		WHEN( "items are dequeued" ) {
            float first = aQueue.dequeue();
            float second = aQueue.dequeue();
			THEN( "the items are dequeued in the order they were added" ) {
                REQUIRE(first == 3.14f);
                REQUIRE(second == -5.3f);
			}

			AND_THEN( "the size decreases" ) {
                REQUIRE(aQueue.getSize() == 0);
			}
		}
	}
}
SCENARIO( "A Queue can have the front element peeked at", "[Queue]") {

	GIVEN( "A empty queue" ) {
        Queue<char> aQueue;

		WHEN( "items are enqueued" ) {
            aQueue.enqueue('a');
            aQueue.enqueue('b');
            aQueue.enqueue('c');

			THEN( "the first element enqueued can be peeked at several times" ) {
                REQUIRE(aQueue.peek() == 'a');
                REQUIRE(aQueue.peek() == 'a');
                REQUIRE(aQueue.peek() == 'a');
			}
		}
        AND_WHEN("there are no elements in the queue") {
            REQUIRE_THROWS_AS(aQueue.dequeue(), std::range_error);
        }
	}

	GIVEN( "A queue with elements enqueued" ) {
        Queue<int> aQueue;
        aQueue.enqueue(12);
        aQueue.enqueue(13);
        aQueue.enqueue(35);

		WHEN( "more items are enqueued" ) {
            aQueue.enqueue(7);
            aQueue.enqueue(77);
            aQueue.enqueue(6);

			THEN( "the first element originally enqueued can be peeked at" ) {
                REQUIRE(aQueue.peek() == 12);
			}
		}

		WHEN( "items are dequeued" ) {
            aQueue.dequeue();
            
			THEN( "the earliest element originally enqueued can be peeked at" ) {
                REQUIRE(aQueue.peek() == 13);
			}
		}
	}
}