# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xcurs
PORTVERSION=	0.5.1
PORTREVISION=	7
CATEGORIES=	x11 python
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ \
		#http://varg.dyndns.org/psi/files/xcurs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editor for new X.Org style full-color cursors properties

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR}

USES=		python:2.7
USE_GNOME=	pygtk2
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,#!/usr/bin/python,#!${PYTHON_CMD},g' \
		${WRKSRC}/parsexcursor.py ${WRKSRC}/xcurs.py
	@${REINPLACE_CMD} -e 's,gtk\.mainquit,gtk\.main_quit,' \
		${WRKSRC}/xcurs.py ${WRKSRC}/gladew.py ${WRKSRC}/filesel.py
	@${REINPLACE_CMD} -e 's,gtk\.mainloop,gtk\.main,' ${WRKSRC}/filesel.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xcurs.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/filesel.py ${WRKSRC}/gladew.py \
		${WRKSRC}/parsexcursor.py ${WRKSRC}/xcursorlist.py \
			${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/xcurs.glade ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
