# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qtada
PORTVERSION=	3.2.0.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.qtada.com/
DISTNAME=	${PORTNAME}-gpl-3.2.0-20120708-3871

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada2005 language bindings to Qt4 framework

LICENSE=	GPLv2

# Error: In library project "Examples_Designer_Custom_Widget_Plugin"
# Unit "Analog_Clock_Plugin" is not in the interface set
# but it is needed by the spec of "Analog_Clock_Plugin.moc"
BROKEN=		New gprbuild detected interface issue with designer example
DEPRECATED=	No development since 2012, usefulness unclear
EXPIRATION_DATE=	2016-09-09

BUILD_DEPENDS=	gprbuild>=20120510:devel/gprbuild \
		asis>=2011:lang/asis

USES=		ada gmake pkgconfig
GNU_CONFIGURE=	yes
USE_QT4=	corelib gui xml designer sql opengl webkit
NO_MTREE=	yes

#CONFIGURE_ARGS=	--with-gtkada=NO

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share
	${MV} ${STAGEDIR}${PREFIX}/examples ${STAGEDIR}${PREFIX}/share/
	@(cd ${STAGEDIR}${PREFIX} ; \
		${FIND} * \( -type f -or -type l \) | ${SORT} >> ${TMPPLIST})
	@(cd ${STAGEDIR}${PREFIX} ; \
		${FIND} * -type d -empty | ${SORT} -r | sed -e 's|^|@dir |' >> ${TMPPLIST})

.include <bsd.port.mk>
