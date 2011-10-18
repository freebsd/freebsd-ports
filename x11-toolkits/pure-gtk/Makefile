# New ports collection makefile for:	pure-gtk
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-gtk
PORTVERSION=	0.10
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	A set of Pure language bindings for GTK+

LIB_DEPENDS+=	pure.7:${PORTSDIR}/lang/pure \
		cairo.2:${PORTSDIR}/graphics/cairo
RUN_DEPENDS+=	${LOCALBASE}/lib/pure/ffi.pure:${PORTSDIR}/devel/pure-ffi

LICENSE_FILE=	${WRKSRC}/COPYING

USE_GCC=	4.2+
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 atk pango

MAKE_ARGS+=	prefix=${PREFIX} CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib CFLAGS="${CFLAGS}"

PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
