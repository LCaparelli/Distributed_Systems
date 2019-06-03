import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.net.InetAddress
import java.net.Socket
import java.util.*
import kotlin.concurrent.thread
import kotlin.system.exitProcess


fun main(args: Array<String>) {
    for (i in 0..999L) {
        thread(start = true) {
            sendRequest(Request(
                    operation = "POST",
                    name = UUID.randomUUID().toString(),
                    address = UUID.randomUUID().toString(),
                    balance = Random().nextFloat())
            )
        }
        Thread.sleep(15)
    }
    exitProcess(0);
}


private fun sendRequest(request: Request) {
    try {
        with(setUpSocket()) {
            val writer = setUpBufferedWriterAndSendRequest(this, request)
            val reader = BufferedReader(InputStreamReader(this.getInputStream()))

            reader.forEachLine { println(it) }

            writer.close()
            reader.close()
        }
    } catch (e: Exception) {
        e.printStackTrace()
    }
}


private fun setUpBufferedWriterAndSendRequest(socket: Socket, request: Request) =
        BufferedWriter(OutputStreamWriter(socket.getOutputStream(), "UTF8")).also {
            it.write(
                    """{"operation":"${request.operation}","name":"${request.name}","address":"${request.address}", "balance":${request.balance}}"""
            )
            it.flush()
        }


private fun setUpSocket(): Socket {
    val hostname = "localhost"
    val port = 8080

    val addr = InetAddress.getByName(hostname)
    return Socket(addr, port)
}


data class Request(
        val operation: String,
        val name: String,
        val address: String,
        val balance: Float
)