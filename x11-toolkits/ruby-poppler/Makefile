# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	poppler
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Poppler

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
BUILD_DEPENDS=	rubygem-pkg-config>=1.0.7:${PORTSDIR}/devel/rubygem-pkg-config
RUN_DEPENDS=	rubygem-pkg-config>=1.0.7:${PORTSDIR}/devel/rubygem-pkg-config

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
CONFIGURE_ARGS=	--with-pkg-config-dir=${LOCALBASE}/libdata/pkgconfig

MASTERDIR=	${.CURDIR}/../../x11/ruby-gnome2
PKGDIR=		${.CURDIR}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/${PORTNAME}
INSTALL_TARGET=	site-install install

DOCS=		COPYING.LIB README

post-patch:
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
