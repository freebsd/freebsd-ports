# Created by: ijliao
# $FreeBSD$

PORTNAME=	xvattr
PORTVERSION=	1.3
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/ \
		http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Getting and setting Xv attributes

OPTIONS_DEFINE=	GTK1
GTK1_DESC=	GTK1 support (Default is GTK2)

USE_XORG=	x11 xv
WANT_GNOME=	yes
USES=		pkgconfig

PLIST_FILES=	bin/${PORTNAME} bin/g${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK1}
USE_GNOME+=	gtk12
GTK_PC=		gtk+
.else
USE_GNOME+=	gtk20
GTK_PC=		gtk+-2.0
.endif

post-extract:
	@${RM} -f ${WRKSRC}/getopt.h

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME} \
		`pkg-config --cflags --libs xv x11`
	cd ${WRKSRC} && ${CC} ${CFLAGS} g${PORTNAME}.c -o g${PORTNAME} \
		`pkg-config --cflags --libs ${GTK_PC} xv x11`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/g${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
