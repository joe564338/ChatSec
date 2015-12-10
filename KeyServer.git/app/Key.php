<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Key extends Model {

    protected $visible = ['username', 'signing_key', 'encryption_key'];

    protected $fillable = ['username', 'signing_key', 'encryption_key'];

}
