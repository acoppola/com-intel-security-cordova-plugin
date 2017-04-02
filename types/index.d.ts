declare namespace intel.security {
    interface SecureData {
        /**
         * Creates a new instance of secure data (using plaintext data)
         * @param  options Data options
         * @return A promise that resolves to the instanceID of the created data instance (Number) or rejects with an errorObj
         */
        createFromData(options: DataOptions): Promise<number>;

        /**
         * Creates a new instance of secure data (using sealed data that was received from getSealedData API)
         * @param  options Sealed data options
         * @return A promise that resolves to the instanceID of the created data instance (Number) or rejects with an errorObj
         */
        createFromSealedData(options: SealedDataOptions): Promise<number>;

        /**
         * Changes the extra key of a secure data instance
         * @param  options Extra key options
         * @return A promise that resolves with no parameters or rejects with an errorObj
         */
        changeExtraKey(options: ExtraKeyOptions): Promise<void>;

        /**
         *  Returns the plaintext data of the secure data instance
         * @param  Valid secure data instance ID
         * @return  A promise that resolves to the data plaintext (String) or rejects with an errorObj
         */
        getData(instanceID: number): Promise<string>;

        /**
         * Returns the sealed chunk of a secure data instance
         * @param  Valid secure data instance ID
         * @return A promise that resolves to the data plaintext (String) or rejects with an errorObj
         */
        getSealedData(instanceID: number): Promise<string>;

        /**
         * Returns the tag of the secure data instance
         * @param  Valid secure data instance ID
         * @return  A promise that resolves to the tag (String) or rejects with an errorObj
         */
        getTag(instanceID: number): Promise<string>;

        /**
         *  Returns the data policy of the secure data instance
         * @param  Valid secure data instance ID
         * @return A promise that resolves to the policy object (Object with fields: appAccessControl, deviceLocality, sensitivityLevel, noStore, noRead)
         */
        getPolicy(instanceID: number): Promise<Policy>;

        /**
         * Returns the data creator unique ID
         * @param  Valid secure data instance ID
         * @return A promise that resolves to the creator unique ID (Number) or rejects with an errorObj
         */
        getCreator(instanceID: number): Promise<number>;

        /**
         *  Returns the list of trusted web domains for the given secure data instance
         * @param  Valid secure data instance ID
         * @return A promise that resolves to a list of web owners (Array of strings) or rejects with an errorObj
         */
        getWebOwners(instanceID: number): Promise<string[]>;

        /**
         *  Releases a secure data instance
         * @param  Valid secure data instance ID
         * @return A promise that resolves with no parameters or rejects with an errorObj
         */
        destroy(instanceID: number): Promise<void>;
    }

    interface Policy {
        /** Application access control policy */
        appAccessControl?: number,
        /** Device locality policy */
        deviceLocality?: number,
        /** Sensitivity level policy */
        sensitivityLevel?: number,
        /** Disallow sealed blob access */
        noStore?: boolean,
        /** Disallow plaintext data access */
        noRead?: boolean,
    }

    interface DataOptions extends Policy {
        /** Plaintext data */
        data: string,
        /** Tag text */
        tag?: string,
        /** Optional extra sealing secret as Secure Data instanceID */
        extraKey?: number,
        /** Array of owners unique ID */
        owners?: number[],
        /** Creator unique ID */
        creator?: number
        /** List of trusted web domains */
        webOwners?: string[]
    }

    interface SealedDataOptions {
        /** Sealed data in String format */
        sealedData: string,
        /** Optional extra sealing secret as Secure Data instanceID */
        extraKey?: number
    }

    interface ExtraKeyOptions {
        /** Secure data instance ID */
        instanceID: number,
        /** Optional extra sealing secret as Secure Data instanceID */
        extraKey: number
    }

    interface SecureStorage {
        /**
         * Reads the data from a secure storage (indicated by id) and creates a new secure data instance
         * @param success  Function that will be triggered when the read operation completes successfully
         * @param fail     Function that will be triggered when read operation fails
         * @param options  Storage read options
         *
         */
        read(
            success: (instanceID: number) => void,
            fail: (errorObj: ErrorObject) => void,
            options: StorageReadOptions): void;

        /**
         * Writes the data contained in a secure data instance ('instanceID') into secure storage ('id')
         * @param success  Function that will be triggered when the write operation completes successfully
         * @param fail     Function that will be triggered when write operation fails
         * @param options  Storage write options
         *
         */
        write(
            success: () => void,
            fail: (errorObj: ErrorObject) => void,
            options: StorageWriteOptions): void;

        /**
         * Deletes a secure storage resource (indicated by id)
         * @param success  Function that will be triggered when the write operation completes successfully
         * @param fail     Function that will be triggered when delete operation fails
         * @param options  Storage delete options
         *
         */
        delete(
            success: () => void,
            fail: (errorObj: ErrorObject) => void,
            options: StorageOptions): void;
    }


    interface StorageOptions {
        /** Storage resource identifier */
        id: string,
        /** Storage type */
        storageType?: number
    }

    interface StorageWriteOptions extends StorageOptions {
        /** Data instance ID */
        instanceID: number,
    }

    interface StorageReadOptions extends StorageOptions {
        /** Optional extra sealing secret as Secure Data instanceID */
        extraKey?: number
    }


    interface SecureTransport {
        /**
         * Creates a new instance of Secure Transport with provided parameters
         * @param success Function that will be triggered when the open operation completes successfully
         * @param fail    Function that will be triggered when the open operation fails
         * @param options Secure transport open options
         *
         */
        open(
            success: (instanceID: number) => void,
            fail: (errorObj: ErrorObject) => void,
            options: OpenOptions): void;

        /**
         * Sets the URL of the Secure Transport instance
         * @param success Function that will be triggered when the set url operation completes successfully
         * @param fail    Function that will be triggered when the set url operation fails
         * @param options Set url options
         *
         */
        setURL(
            success: () => void,
            fail: (errorObj: ErrorObject) => void,
            options: SetUrlOptions): void;

        /**
         * Sets the HTTP method of the Secure Transport instance
         * @param success Function that will be triggered when the set method operation completes successfully
         * @param fail    Function that will be triggered when the set method operation fails
         * @param options Set method options
         *
         */
        setMethod(
            success: () => void,
            fail: (errorObj: ErrorObject) => void,
            options: SetMethodOptions): void;

        /**
         * Sets the request header of the Secure Transport instance
         * @param success Function that will be triggered when the set headers operation completes successfully
         * @param fail    Function that will be triggered when the set headers operation fails
         * @param options Set header options
         *
         */
        setHeaders(
            success: () => void,
            fail: (errorObj: ErrorObject) => void,
            options: SetHeadersOptions): void;

        /**
         * Establishes a secure connection and sends the request
         * @param success  Function that will be triggered when the set request operation completes successfully
         * @param fail     Function that will be triggered when the set request operation fails
         * @param options  Send request options
         *
         */
        sendRequest(
            success: (response: Response) => void,
            fail: (errorObj: ErrorObject) => void,
            options: SendRequestOptions): void;

        /**
         * Aborts a pending send request of the Secure Transport instance
         * @param success     Function that will be triggered when the abort operation completes successfully
         * @param fail        Function that will be triggered when the abort operation fails
         * @param instanceID  Valid secure transport instance ID
         *
         */
        abort(
            success: () => void,
            fail: (errorObj: ErrorObject) => void,
            instanceID: number): void;

        /**
         * Releases a secure transport instance
         * @param success     Function that will be triggered when the destroy operation completes successfully
         * @param fail        Function that will be triggered when the destroy operation fails
         * @param instanceID  Valid secure transport instance ID
         *
         */
        destroy(
            success: () => void,
            fail: (errorObj: ErrorObject) => void,
            instanceID: number): void;
    }

    /** Http methods */
    type HttpMethod = "GET" | "POST" | "PUT" | "DELETE" | "HEAD" | "OPTIONS";
    /** Request formats */
    type RequestFormat = "GENERIC" | "JSON";

    interface OpenOptions {
        /** URL of the server domain and resource locator */
        url: string,
        /** HTTP method */
        method?: HttpMethod,
        /** Server public certificate in PEM format for certificate pinning */
        serverKey?: string,
        /** Response waiting time-out in milliseconds */
        timeout?: number
    }

    interface Response {
        /** Response HTTP status */
        responseHttpStatus: string,
        /* Response header  - ssociative array of key:value pairs*/
        responseHeader: any
        /** Resposne body */
        responseBody: string
    }


    interface SetUrlOptions {
        /** Transport Instance ID */
        instanceID: number,
        /** URL of the server domain and resource locator */
        url: string,
        /** Server public certificate in PEM format for certificate pinning */
        serverKey?: string
    }


    interface SetMethodOptions {
        /** Transport Instance ID */
        instanceID?: number,
        /** HTTP method */
        method: HttpMethod
    }


    interface SetHeadersOptions {
        /** Transport Instance ID */
        instanceID: number,
        /** List of Key:Value strings pairs */
        headers?: {
            [index: string]: string
        }
    }

    interface SendRequestOptions {
        /** Transport Instance ID */
        instanceID: number,
        /** Data to send */
        requestBody?: string,
        /** The format of the request body */
        requestFormat?: RequestFormat,
        /** An array of descriptors */
        secureDataDescriptors?: any
    }

    interface ErrorObject {
        code: number,
        message: string
    }

    var secureData: SecureData;
    var secureStorage: SecureStorage;
    var secureTransport: SecureTransport;
    var errorObject: {
        new (code?: number, message?: string): ErrorObject;
    }
}