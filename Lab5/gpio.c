#include <linux/gpio.h>
// read linux/include/uapi/linux/gpio.h 
// for the details

#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#define LOW 0
#define HIGH 1

int main(int argc, char *argv[]){
    int fd0 = open("/dev/gpiochip0", O_RDWR);
    struct gpiochip_info cinfo;

    ioctl(fd0, GPIO_GET_CHIPINFO_IOCTL, &cinfo);
    fprintf(stdout, "GPIO chip 0: %s, \"%s\", %u lines\n", cinfo.name, cinfo.label, cinfo.lines);

    /* Task 1a: toggle green and yellow for 5 times */
    struct gpiohandle_request req_GY;
    struct gpiohandle_data data_GY;
    req_GY.lines = 2;
    req_GY.lineoffsets[0] = 4;
    req_GY.lineoffsets[1] = 17;
    req_GY.flags = GPIOHANDLE_REQUEST_OUTPUT;
    data_GY.values[0] = 1;
    data_GY.values[1] = 0;

    ioctl(fd0, GPIO_GET_LINE_HANDLE_IOCTL, &req_GY);

    for(int i=0;i<5;i++){
        ioctl(req_GY.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data_GY);
        usleep(1000000);
        data_GY.values[0] = !data_GY.values[0];
        data_GY.values[1] = !data_GY.values[1];
    }
    close(req_GY.fd);

    /* Task 1b: code out the button part */
    struct gpiohandle_request req_pb, req_R;
    struct gpiohandle_data data_pb, data_R;

    req_pb.lines = 1;
    req_pb.lineoffsets[0] = 11;
    req_pb.flags = GPIOHANDLE_REQUEST_INPUT;

    req_R.lines = 1;
    req_R.lineoffsets[0] = 27;
    req_R.flags = GPIOHANDLE_REQUEST_OUTPUT;

    ioctl(fd0, GPIO_GET_LINE_HANDLE_IOCTL, &req_pb);
    ioctl(fd0, GPIO_GET_LINE_HANDLE_IOCTL, &req_R);

    while(1){
        ioctl(req_pb.fd, GPIOHANDLE_GET_LINE_VALUES_IOCTL, &data_pb);
        if(data_pb[0])
        {
            setGPIO(&req_R, &data_R, HIGH);
            usleep(50000);
            setGPIO(&req_R, &data_R, LOW);
            usleep(50000);
        }
    }
    close(req_pb.fd);
    close(req_R.fd);

    close(fd0);
    exit(EXIT_SUCCESS);
}

void setGPIO(struct gpiohandle_request *req, struct gpiohandle_data *data, int mode){
    if(mode == HIGH) data[0] = HIGH;
    else data[0] = LOW;

    ioctl(req.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, data);
}