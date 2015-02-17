#include "UDP_Listener.h"

UDP_Listener::UDP_Listener(const std::string &port) :
		port(port) {

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&masterfds);
	FD_ZERO(&readfds);

	int status;
	struct addrinfo hints, *servinfo, *p;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;

	if ((status = getaddrinfo(NULL, port.c_str(), &hints, &servinfo)) != 0) {
		fprintf(stderr, "cRIO: getaddrinfo: %s\n", gai_strerror(status));
	}

	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol))
				== -1) {
			std::cerr << "cRIO: socket" << std::endl;
			continue;
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			std::cerr << "cRIO: bind" << std::endl;
			continue;
		}
		break;
	}

	if (p == NULL) {
		fprintf(stderr, "cRIO: failed to bind\n");
	}
	freeaddrinfo(servinfo);

	FD_SET(sockfd, &masterfds);
	FD_SET(sockfd, &readfds);
	fdmax = sockfd;
}

UDP_Listener::~UDP_Listener() {
	close(sockfd);
}

std::string UDP_Listener::recv() {

	msg.clear();
	char buf[BYTESMAX];
	int bytesn;
	readfds = masterfds;
	if (select(fdmax + 1, &readfds, nullptr, nullptr, &tv) == -1) {
		std::cerr << "select" << std::endl;
		msg = RECV_ERROR;
		return msg;
	}
	for (int i = 0; i <= fdmax; ++i) {
		if (FD_ISSET(i, &readfds)) {
			addr_len = sizeof(their_addr);

			if ((bytesn = recvfrom(sockfd, buf, BYTESMAX - 1, 0,
					(struct sockaddr *) &their_addr, &addr_len)) == -1) {
				std::cerr << "recvfrom" << std::endl;
				msg = RECV_ERROR;
			} else {
				buf[bytesn] = '\0';

				msg.resize(bytesn);
				msg = buf;
			}
		}
	}
	return msg;
}
