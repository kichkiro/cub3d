FROM bitnami/minideb:bookworm

RUN apt-get update && \
	apt-get install -y build-essential && \
	apt-get clean && \
	rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/app

COPY project/ minirt/

WORKDIR /usr/src/app/minirt/

RUN make

ENTRYPOINT [ "tail", "-f" ]
