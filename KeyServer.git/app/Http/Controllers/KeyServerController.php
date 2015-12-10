<?php

namespace App\Http\Controllers;

use App\Key;
use Input;

class KeyServerController extends Controller {

    public function postKeys() {

        $key = Key::createOrFail(Input::all());

        $key->save();

        return $key;

    }

    public function getKeys($username) {

        $key = Key::where('username',$username)->first();

        return $key;

    }

}