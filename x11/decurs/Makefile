# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	decurs
PORTVERSION=	0.55.1
PORTREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ \
		#http://varg.dyndns.org/psi/files/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple X11 mouse cursor editor

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkmm-2.0.so:${PORTSDIR}/x11-toolkits/gtkmm20

USES=		dos2unix pkgconfig
DOS2UNIX_FILES=	src/cppstring.cc
USE_XORG=	x11
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		${FILESDIR}/decurs.exec > ${WRKSRC}/decurs.exec
	@${REINPLACE_CMD} -E 's/^\/\/ friend// ; \
		s/([^:])ostream/\1std::ostream/g ; \
		s/CppString \&str/const &/' ${WRKSRC}/src/cppstring.hh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/decurs \
		${STAGEDIR}${PREFIX}/bin/decurs.bin
	${INSTALL_SCRIPT} ${WRKSRC}/decurs.exec ${STAGEDIR}${PREFIX}/bin/decurs
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.bdf ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
