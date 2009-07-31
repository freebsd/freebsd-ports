# New ports collection makefile for:	Ruby/GTK2
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/ruby-gtk2/Makefile,v 1.5 2007/10/05 05:06:39 mezz Exp $
#

PORTNAME=	gtk2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GTK+2

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/pango.so:${PORTSDIR}/x11-toolkits/ruby-pango
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/atk.so:${PORTSDIR}/accessibility/ruby-atk \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/pango.so:${PORTSDIR}/x11-toolkits/ruby-pango

USE_RUBY=	yes
USE_GNOME=	gtk20
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gtk
INSTALL_TARGET=	site-install

DOCS=		COPYING.LIB ChangeLog README

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/sample/gtk-demo/common.rb
	@${REINPLACE_CMD} -e 's|local/bin/ruby|bin/env ruby|g' \
		${WRKSRC}/sample/misc/button2.rb
	@${REINPLACE_CMD} -e 's|/usr/local/share|${LOCALBASE}/share|g' \
			${WRKSRC}/sample/testgtk/testgtk*
	@${FIND} ${WRKSRC} -name '*.bak' -delete

# Have to do that to generate ruby-glib's glib-enum-types.h or
# it will not build.
pre-configure:
	@(cd ${RUBY_GNOME_WRKSRC}/glib ; ${SETENV} ${CONFIGURE_ENV} \
		${RUBY} ${RUBY_FLAGS} ${RUBY_EXTCONF} ${CONFIGURE_ARGS})

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/gtk-demo
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/misc
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/testgtk
	@${INSTALL_DATA} ${WRKSRC}/sample/gtk-demo/* ${RUBY_MODEXAMPLESDIR}/gtk-demo/
	@${INSTALL_DATA} ${WRKSRC}/sample/misc/* ${RUBY_MODEXAMPLESDIR}/misc/
	@${INSTALL_DATA} ${WRKSRC}/sample/testgtk/* ${RUBY_MODEXAMPLESDIR}/testgtk/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
