FROM python:slim

RUN pip install --no-cache-dir numpy && \
    useradd -d /home/ctf ctf && \
    mkdir -p /home/ctf/app/ && \
    chown -R ctf:ctf /home/ctf

CMD ["sleep", "infinity"]
