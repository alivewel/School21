# Day 03 - Go Intensive

## Tasty Discoveries

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) \
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) \
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 00: Loading Data](#exercise-00-loading-data)
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 01: Simplest Interface](#exercise-01-simplest-interface)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 02: Proper API](#exercise-02-proper-api)
7. [Chapter VII](#chapter-vii) \
    7.1. [Exercise 03: Closest Restaurants](#exercise-03-closest-restaurants)
8. [Chapter VIII](#chapter-viii) \
    8.1. [Exercise 04: JWT](#exercise-04-jwt)


<h2 id="chapter-i" >Chapter I</h2>
<h2 id="general-rules" >General rules</h2>

- Ваши программы не должны завершать работу неожиданно (выдавая ошибку при правильном вводе). Если это произойдет, ваш проект будет считаться нефункциональным и при оценке получит 0 баллов.
- Мы рекомендуем вам создавать тестовые программы для вашего проекта, даже если эту работу не нужно будет отправлять и она не будет оцениваться. Это даст вам возможность легко проверить свою работу и работу своих коллег. Вы найдете эти тесты особенно полезными во время вашей защиты. Действительно, во время защиты вы можете использовать свои тесты и/или тесты коллеги, которого вы оцениваете.
- Отправьте свою работу в назначенный вам репозиторий git. Оцениваться будет только работа в репозитории git.
- Если ваш код использует внешние зависимости, для управления ими следует использовать [Go Modules](https://go.dev/blog/using-go-modules).

<h2 id="chapter-ii" >Chapter II</h2>
<h2 id="rules-of-the-day" >Rules of the day</h2>

- Вам следует сдавать только файлы `*.go` и (в случае внешних зависимостей) `go.mod` + `go.sum`
- Ваш код для этой задачи должен быть готов к сборке с помощью команды go build.
- Все входные данные ('page'/'lat'/'long') должны быть тщательно проверены и никогда не вызывать HTTP 500 (приемлем только HTTP 400/401 со значимым сообщением об ошибке, как описано в EX02).

<h2 id="chapter-iii" >Chapter III</h2>
<h2 id="intro" >Intro</h2>

Людям обычно нравятся некоторые рекомендуемые приложения. Это помогает не слишком много думать о том, что купить, куда пойти и что поесть.

Кроме того, практически у каждого есть телефон с геолокацией. Как часто вы пытались найти какой-нибудь ресторан в вашем районе, чтобы поужинать?

Давайте немного подумаем о том, как работают эти сервисы, и создадим свой собственный, очень простой, не так ли?

<h2 id="chapter-iv" >Chapter IV</h2>
<h3 id="ex00">Exercise 00: Loading Data</h3>

На рынке существует множество различных баз данных. Но поскольку мы пытаемся предоставить возможность поиска, давайте воспользуемся [Elasticsearch](https://www.elastic.co/downloads/elasticsearch). Все предоставленные примеры были протестированы на версии 7.9.2.

Elasticsearch — это система полнотекстового поиска, созданная на базе [Lucene](https://en.wikipedia.org/wiki/Apache_Lucene). Он предоставляет HTTP API, который мы будем использовать в этой задаче.

Предоставленный нами набор данных о ресторанах (взятый с портала открытых данных) состоит из более чем 13 тысяч ресторанов в районе Москвы, Россия (вы можете собрать другой аналогичный набор данных для любого другого места, которое захотите). Каждая запись имеет:

- ID
- Name
- Address
- Phone
- Longitude
- Latitude

- ИДЕНТИФИКАТОР
- Имя
- Адрес
- Телефон
- Долгота
- Широта

Прежде чем загружать все записи в базу данных, давайте создадим индекс и маппинг (явно указав типы данных). Без этого Elasticsearch будет пытаться угадать типы полей на основе предоставленных документов, а иногда и не распознавать геоточки.

Вот пара ссылок, которые помогут вам начать работу:
- https://www.elastic.co/guide/en/elasticsearch/reference/7.9/indices-create-index.html
- https://www.elastic.co/guide/en/elasticsearch/reference/7.9/geo-point.html

Запустите базу данных, запустив `~$ /path/to/elasticsearch/dir/bin/elasticsearch` и давайте поэкспериментируем.

Для простоты давайте использовать «места» в качестве имени индекса и «место» в качестве имени записи. Вы можете создать индекс, используя cURL, следующим образом:

```
~$ curl -XPUT "http://localhost:9200/places"
```

но в этой задаче вам следует использовать привязки Go Elasticsearch, чтобы сделать то же самое. Следующее, что вам нужно сделать, это предоставить сопоставления типов для наших данных. С cURL это будет выглядеть так:

```
~$ curl -XPUT http://localhost:9200/places/place/_mapping?include_type_name=true -H "Content-Type: application/json" -d @"schema.json"
```

where `schema.json` looks like this:

```
{
  "properties": {
    "name": {
        "type":  "text"
    },
    "address": {
        "type":  "text"
    },
    "phone": {
        "type":  "text"
    },
    "location": {
      "type": "geo_point"
    }
  }
}
```

Еще раз: если команды cURL являются лишь справочной информацией для самотестирования, это действие должна выполнять написанная вами программа Go.

Теперь у вас есть набор данных для загрузки. Для этого вам следует использовать [Bulk API](https://www.elastic.co/guide/en/elasticsearch/reference/7.9/docs-bulk.html). Все существующие привязки Elasticsearch предоставляют для него оболочки, например [вот хороший пример](https://github.com/elastic/go-elasticsearch/blob/master/_examples/bulk/indexer.go) для официального клиента (имейте в виду, что вам нужно будет использовать клиент v7 для ES версии 7.9, а не v8). Есть также пара сторонних клиентов, выбирайте тот, который вам больше нравится.

Чтобы проверить себя, вы можете использовать cURL. Так,

```
~$ curl -s -XGET "http://localhost:9200/places"
```

должно вывести что-то вроде этого:

```
{
  "places": {
    "aliases": {},
    "mappings": {
      "properties": {
        "address": {
          "type": "text"
        },
        "id": {
          "type": "long"
        },
        "location": {
          "type": "geo_point"
        },
        "name": {
          "type": "text"
        },
        "phone": {
          "type": "text"
        }
      }
    },
    "settings": {
      "index": {
        "creation_date": "1601810777906",
        "number_of_shards": "1",
        "number_of_replicas": "1",
        "uuid": "4JKa9fgISd6-N130rpNYtQ",
        "version": {
          "created": "7090299"
        },
        "provided_name": "places"
      }
    }
  }
}
```

и запрос записи по ее идентификатору будет выглядеть так:

```
~$ curl -s -XGET "http://localhost:9200/places/place/1"
```

```
{
  "_index": "places",
  "_type": "place",
  "_id": "1",
  "_version": 1,
  "_seq_no": 0,
  "_primary_term": 1,
  "found": true,
  "_source": {
    "id": 1,
    "name": "SMETANA",
    "address": "gorod Moskva, ulitsa Egora Abakumova, dom 9",
    "phone": "(499) 183-14-10",
    "location": {
      "lat": 55.879001531303366,
      "lon": 37.71456500043604
    }
  }
}
```

Обратите внимание, что запись с ID=1 может отличаться от записи в наборе данных, если вы решили использовать горутины для ускорения процесса (хотя в этой задаче это не является обязательным требованием).

<h2 id="chapter-v" >Chapter V</h2>
<h3 id="ex01">Exercise 01: Simplest Interface</h3>

Теперь давайте создадим HTML-интерфейс для нашей базы данных. Ничего особенного, нам просто нужно отобразить страницу со списком имен, адресов и телефонов, чтобы пользователь мог видеть ее в браузере.

Вы должны абстрагировать свою базу данных за интерфейсом. Чтобы просто вернуть список записей и иметь возможность [разбивать на страницы](https://www.elastic.co/guide/en/elasticsearch/reference/current/paginate-search-results.html) по ним, этого интерфейса достаточно:

```
type Store interface {
    // returns a list of items, a total number of hits and (or) an error in case of one
    // возвращает список элементов, общее количество попаданий и (или) ошибку в случае одного
    GetPlaces(limit int, offset int) ([]types.Place, int, error)
}
```

Импорт, связанный с Elasticsearch, должен быть в пакете main, так как все, что связано с базой данных, должно находиться в пакете db внутри вашего проекта, и вам следует использовать этот интерфейс только для взаимодействия с ним.

Ваше HTTP-приложение должно работать на порту 8888, отвечая списком ресторанов и обеспечивая простую нумерацию страниц. Так. при запросе «http://127.0.0.1:8888/?page=2» (обратите внимание на параметр GET «page») вы должны получить следующую страницу:

```
<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <title>Places</title>
    <meta name="description" content="">
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body>
<h5>Total: 13649</h5>
<ul>
    <li>
        <div>Sushi Wok</div>
        <div>gorod Moskva, prospekt Andropova, dom 30</div>
        <div>(499) 754-44-44</div>
    </li>
    <li>
        <div>Ryba i mjaso na ugljah</div>
        <div>gorod Moskva, prospekt Andropova, dom 35A</div>
        <div>(499) 612-82-69</div>
    </li>
    <li>
        <div>Hleb nasuschnyj</div>
        <div>gorod Moskva, ulitsa Arbat, dom 6/2</div>
        <div>(495) 984-91-82</div>
    </li>
    <li>
        <div>TAJJ MAHAL</div>
        <div>gorod Moskva, ulitsa Arbat, dom 6/2</div>
        <div>(495) 107-91-06</div>
    </li>
    <li>
        <div>Balalaechnaja</div>
        <div>gorod Moskva, ulitsa Arbat, dom 23, stroenie 1</div>
        <div>(905) 752-88-62</div>
    </li>
    <li>
        <div>IL Pizzaiolo</div>
        <div>gorod Moskva, ulitsa Arbat, dom 31</div>
        <div>(495) 933-28-34</div>
    </li>
    <li>
        <div>Bufet pri Astrahanskih banjah</div>
        <div>gorod Moskva, Astrahanskij pereulok, dom 5/9</div>
        <div>(495) 344-11-68</div>
    </li>
    <li>
        <div>MU-MU</div>
        <div>gorod Moskva, Baumanskaja ulitsa, dom 35/1</div>
        <div>(499) 261-33-58</div>
    </li>
    <li>
        <div>Bek tu Blek</div>
        <div>gorod Moskva, Tatarskaja ulitsa, dom 14</div>
        <div>(495) 916-90-55</div>
    </li>
    <li>
        <div>Glav Pirog</div>
        <div>gorod Moskva, Begovaja ulitsa, dom 17, korpus 1</div>
        <div>(926) 554-54-08</div>
    </li>
</ul>
<a href="/?page=1">Previous</a>
<a href="/?page=3">Next</a>
<a href="/?page=1364">Last</a>
</body>
</html>
```

Ссылка "Previous" (Предыдущая) должна исчезнуть на первой странице, а ссылка "Next" должна исчезнуть на последней странице.

ВАЖНОЕ ПРИМЕЧАНИЕ. Вы можете заметить, что по умолчанию Elasticsearch не позволяет вам работать с нумерацией страниц для более чем 10 000 записей. Есть два способа добиться этого: либо использовать API прокрутки (см. ту же ссылку на разбиение на страницы выше), либо просто увеличить предел в настройках индекса специально для этой задачи. Последнее приемлемо для этой задачи, но не рекомендуется использовать его в производственной среде. Запрос, который поможет вам установить его, приведен ниже:

```
~$ curl -XPUT -H "Content-Type: application/json" "http://localhost:9200/places/_settings" -d '
{
  "index" : {
    "max_result_window" : 20000
  }
}'
```

Кроме того, если для параметра «страница» указано неправильное значение (за пределами [0..last_page] или не числовое), ваша страница должна вернуть ошибку HTTP 400 и обычный текст с описанием ошибки:

```
Invalid 'page' value: 'foo'
```

<h2 id="chapter-vi" >Chapter VI</h2>
<h3 id="ex02">Exercise 02: Proper API</h3>

В современном мире большинство приложений предпочитают API простому HTML. Итак, в этом упражнении все, что вам нужно сделать, это реализовать еще один обработчик, который отвечает «Content-Type: application/json» и версией JSON того же самого, что и в Ex01 (пример для http://127.0.0.1:8888/api /places?page=3):

```
{
  "name": "Places",
  "total": 13649,
  "places": [
    {
      "id": 65,
      "name": "AZERBAJDZhAN",
      "address": "gorod Moskva, ulitsa Dem'jana Bednogo, dom 4",
      "phone": "(495) 946-34-30",
      "location": {
        "lat": 55.769830485601204,
        "lon": 37.486914061171504
      }
    },
    {
      "id": 69,
      "name": "Vojazh",
      "address": "gorod Moskva, Beskudnikovskij bul'var, dom 57, korpus 1",
      "phone": "(499) 485-20-00",
      "location": {
        "lat": 55.872553383512496,
        "lon": 37.538326789741
      }
    },
    {
      "id": 70,
      "name": "GBOU Shkola № 1411 (267)",
      "address": "gorod Moskva, ulitsa Bestuzhevyh, dom 23",
      "phone": "(499) 404-15-09",
      "location": {
        "lat": 55.87213179130298,
        "lon": 37.609625999999984
      }
    },
    {
      "id": 71,
      "name": "Zhigulevskoe",
      "address": "gorod Moskva, Bibirevskaja ulitsa, dom 7, korpus 1",
      "phone": "(964) 565-61-28",
      "location": {
        "lat": 55.88024342230735,
        "lon": 37.59308635976602
      }
    },
    {
      "id": 75,
      "name": "Hinkal'naja",
      "address": "gorod Moskva, ulitsa Marshala Birjuzova, dom 16",
      "phone": "(499) 728-47-01",
      "location": {
        "lat": 55.79476126986192,
        "lon": 37.491709793339744
      }
    },
    {
      "id": 76,
      "name": "ShAURMA ZhI",
      "address": "gorod Moskva, ulitsa Marshala Birjuzova, dom 19",
      "phone": "(903) 018-74-64",
      "location": {
        "lat": 55.794378830665885,
        "lon": 37.49112002224252
      }
    },
    {
      "id": 80,
      "name": "Bufet Shkola № 554",
      "address": "gorod Moskva, Bolotnikovskaja ulitsa, dom 47, korpus 1",
      "phone": "(929) 623-03-21",
      "location": {
        "lat": 55.66186417434049,
        "lon": 37.58323602169326
      }
    },
    {
      "id": 83,
      "name": "Kafe",
      "address": "gorod Moskva, 1-j Botkinskij proezd, dom 2/6",
      "phone": "(495) 945-22-34",
      "location": {
        "lat": 55.781141341601696,
        "lon": 37.55643137063551
      }
    },
    {
      "id": 84,
      "name": "STARYJ BATUM'",
      "address": "gorod Moskva, ulitsa Akademika Bochvara, dom 7, korpus 1",
      "phone": "(495) 942-44-85",
      "location": {
        "lat": 55.8060307318284,
        "lon": 37.461669109923506
      }
    },
    {
      "id": 89,
      "name": "Cheburechnaja SSSR",
      "address": "gorod Moskva, Bol'shaja Bronnaja ulitsa, dom 27/4",
      "phone": "(495) 694-54-76",
      "location": {
        "lat": 55.764134959774346,
        "lon": 37.60256453956346
      }
    }
  ],
  "prev_page": 2,
  "next_page": 4,
  "last_page": 1364
}
```

Кроме того, если для параметра «страница» указано неправильное значение (за пределами [0..last_page] или не числовое), ваш API должен ответить соответствующей ошибкой HTTP 400 и аналогичным JSON:

```
{
    "error": "Invalid 'page' value: 'foo'"
}
```

<h2 id="chapter-vii" >Chapter VII</h2>
<h3 id="ex03">Exercise 03: Closest Restaurants</h3>

Теперь давайте реализуем нашу основную функцию — поиск *трех* ближайших ресторанов! Для этого вам необходимо настроить сортировку для вашего запроса:

```
"sort": [
    {
      "_geo_distance": {
        "location": {
          "lat": 55.674,
          "lon": 37.666
        },
        "order": "asc",
        "unit": "km",
        "mode": "min",
        "distance_type": "arc",
        "ignore_unmapped": true
      }
    }
]
```

где «широта» и «долгота» — ваши текущие координаты. Итак, для URL-адреса http://127.0.0.1:8888/api/recommend?lat=55.674&lon=37.666 ваше приложение должно возвращать JSON следующим образом:

```
{
  "name": "Recommendation",
  "places": [
    {
      "id": 30,
      "name": "Ryba i mjaso na ugljah",
      "address": "gorod Moskva, prospekt Andropova, dom 35A",
      "phone": "(499) 612-82-69",
      "location": {
        "lat": 55.67396575768212,
        "lon": 37.66626689310591
      }
    },
    {
      "id": 3348,
      "name": "Pizzamento",
      "address": "gorod Moskva, prospekt Andropova, dom 37",
      "phone": "(499) 612-33-88",
      "location": {
        "lat": 55.673075576456,
        "lon": 37.664533747576
      }
    },
    {
      "id": 3347,
      "name": "KOFEJNJa «KAPUChINOFF»",
      "address": "gorod Moskva, prospekt Andropova, dom 37",
      "phone": "(499) 612-33-88",
      "location": {
        "lat": 55.672865251005106,
        "lon": 37.6645689561318
      }
    }
  ]
}
```

<h2 id="chapter-viii" >Chapter VIII</h2>
<h3 id="ex04">Exercise 04: JWT</h3>

Итак, последнее (но не менее важное), что нам нужно сделать, — это обеспечить простую форму аутентификации. В настоящее время одним из самых популярных способов реализации этого для API является использование [JWT](https://jwt.io/introduction/). К счастью, в Go есть довольно хороший набор инструментов для решения этой проблемы.

Во-первых, вам необходимо реализовать конечную точку API http://127.0.0.1:8888/api/get_token, единственной целью которой будет создание токена и его возврат, как показано ниже (это пример, ваш токен, скорее всего, будет другим). :

```
{
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhZG1pbiI6dHJ1ZSwiZXhwIjoxNjAxOTc1ODI5LCJuYW1lIjoiTmlrb2xheSJ9.FqsRe0t9YhvEC3hK1pCWumGvrJgz9k9WvhJgO8HsIa8"
}
```

Не забудьте установить заголовок Content-Type: application/json.

Во-вторых, вам необходимо защитить свою конечную точку `/api/recommend` с помощью промежуточного программного обеспечения JWT, которое будет проверять достоверность этого токена.

Таким образом, по умолчанию при запросе этого API из браузера он теперь должен завершаться ошибкой HTTP 401, но работает, когда клиент указывает заголовок `Authorization: Bearer <token>` (вы можете проверить это с помощью cURL или Postman).

Это самый простой способ обеспечить аутентификацию, сейчас нет необходимости вдаваться в подробности.


